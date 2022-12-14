from cgitb import reset
from flask import Flask, g, request, jsonify
from pygame import Cursor
import pyodbc
from connect_db import connect_db
import sys
import time, datetime


app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World!'

def get_db():
    """Opens a new database connection if there is none yet for the
    current application context.
    """
    if not hasattr(g, 'azure_db'):
        g.azure_db = connect_db()
        g.azure_db.autocommit = True
        g.azure_db.set_attr(pyodbc.SQL_ATTR_TXN_ISOLATION, pyodbc.SQL_TXN_SERIALIZABLE)
    return g.azure_db

@app.teardown_appcontext
def close_db(error):
    """Closes the database again at the end of the request."""
    if hasattr(g, 'azure_db'):
        g.azure_db.close()



@app.route('/login')
def login():
    username = request.args.get('username', "")
    password = request.args.get('password', "")
    cid = -1
    #print (username, password)
    conn = get_db()
    #print (conn)
    cursor = conn.execute("SELECT * FROM Customer WHERE username = ? AND password = ?", (username, password))
    records = cursor.fetchall()
    #print records
    if len(records) != 0:
        cid = records[0][0]
    response = {'cid': cid}
    return jsonify(response)




@app.route('/getRenterID')
def getRenterID():
    """
       This HTTP method takes mid as input, and
       returns cid which represents the customer who is renting the movie.
       If this movie is not being rented by anyone, return cid = -1
    """
    mid = (request.args.get('mid', -1))

    # WRITE YOUR CODE HERE
    print("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
    cid = -1
    conn = get_db()
    cursor = conn.execute("""SELECT * FROM Rental WHERE mid = {} AND status = 'open';""".format(mid))
    records = cursor.fetchall()
    if len(records) != 0:
        cid = records[0][0]
    response = {'cid': cid}
    return jsonify(response)



@app.route('/getRemainingRentals')
def getRemainingRentals():
    """
        This HTTP method takes cid as input, and returns n which represents
        how many more movies that cid can rent.

        n = 0 means the customer has reached its maximum number of rentals.
    """
    cid = int(request.args.get('cid', -1))
    conn = get_db()
    # Tell ODBC that you are starting a multi-statement transaction
    conn.autocommit = False
    # WRITE YOUR CODE HERE
    n = getRemainingRentalHelper(cid, conn)
    conn.autocommit = True
    response = {"remain": n}
    return jsonify(response)





def currentTime():
    ts = time.time()
    return datetime.datetime.fromtimestamp(ts).strftime('%Y-%m-%d %H:%M:%S')


@app.route('/rent')
def rent():
    """
        This HTTP method takes cid and mid as input, and returns either "success" or "fail".

        It returns "fail" if C1, C2, or both are violated:
            C1. at any time a movie can be rented to at most one customer.
            C2. at any time a customer can have at most as many movies rented as his/her plan allows.
        Otherwise, it returns "success" and also updates the database accordingly.
    """
    cid = int(request.args.get('cid', -1))
    mid = int(request.args.get('mid', -1))

    conn = get_db()
    
     # Tell ODBC that you are starting a multi-statement transaction
    conn.autocommit = False

    # WRITE YOUR CODE HERE
    Cursor = conn.execute("""
                        select count(mid)
                        from [dbo].[Rental]
                        where status = 'open' and mid = {}; 
                          """.format(mid))
    
    isRented = Cursor.fetchall()[0][0]
    
    n = getRemainingRentalHelper(cid, conn)

    conn.autocommit = True
    
    if int(isRented) == 0 and n > 0:
        response = {"rent": "success"}
        conn.execute("""
                    insert into Rental values({}, {}, '{}', 'open'); 
                     """.format(cid, mid, currentTime()))
    else:
        response = {"rent": "fail"}


    #response = {"rent": "success"} OR response = {"rent": "fail"}
    return jsonify(response)

def getRemainingRentalHelper(cid, conn):
    Cursor = conn.execute("""
                        select c.cid, c.pid, rp.pid, rp.max_movies
                        from Customer c, RentalPlan rp 
                        where c.pid = rp.pid and c.cid = {};
                           """.format(cid)) 
    maxMovies = Cursor.fetchall()[0][3]
    
    Cursor = conn.execute("""
                        select count(*)
                        from Rental
                        where status = 'open' and cid = {};
                           """.format(cid))
    currentMovies = Cursor.fetchall()[0][0]
    return maxMovies - currentMovies