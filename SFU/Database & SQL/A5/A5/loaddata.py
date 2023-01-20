import pyodbc
from connect_db import connect_db


def loadRentalPlan(filename, conn):
    """
        Input:
            $filename: "RentalPlan.txt"
            $conn: you can get it by calling connect_db()
        Functionality:
            1. Create a table named "RentalPlan" in the "VideoStore" database on Azure
            2. Read data from "RentalPlan.txt" and insert them into "RentalPlan"
               * Columns are separated by '|'
               * You can use executemany() to insert multiple rows in bulk
    """
    # WRITE YOUR CODE HERE

    cursor = conn.cursor()

    cursor.execute("""CREATE TABLE RentalPlan(
                pid INTEGER PRIMARY KEY,
                pname VARCHAR(50),
                monthly_fee FLOAT,
                max_movies INTEGER
            )""")

    file = open(filename, "r")
    num_of_lines =  file.readlines()

    inputs = []

    for l in num_of_lines:
        pid,pname,monthly_fee,max_movies = l.strip().split('|')
        input = (pid,pname,monthly_fee,max_movies)
        inputs.append(input)
    
    file.close()
    cursor.executemany("INSERT INTO RentalPlan Values (?,?,?,?)", inputs)
    conn.commit()
    

def loadCustomer(filename, conn):
    """
        Input:
            $filename: "Customer.txt"
            $conn: you can get it by calling connect_db()
        Functionality:
            1. Create a table named "Customer" in the "VideoStore" database on Azure
            2. Read data from "Customer.txt" and insert them into "Customer".
               * Columns are separated by '|'
               * You can use executemany() to insert multiple rows in bulk
    """
    #WRITE YOUR CODE HERE

    cursor = conn.cursor()

    cursor.execute("""CREATE TABLE Customer(
                cid INTEGER PRIMARY KEY,
                pid INTEGER FOREIGN KEY REFERENCES RentalPlan(pid) ON DELETE CASCADE,
                username VARCHAR(50),
                password VARCHAR(50)
                )""")

    file = open(filename, "r")
    num_of_lines =  file.readlines()

    inputs = []

    for l in num_of_lines:
        cid,pid,username,password = l.strip().split('|')
        input = (cid,pid,username,password)
        inputs.append(input)
    
    file.close()
    cursor.executemany("INSERT INTO Customer Values (?,?,?,?)", inputs)
    conn.commit()
    

def loadMovie(filename, conn):
    """
        Input:
            $filename: "Movie.txt"
            $conn: you can get it by calling connect_db()
        Functionality:
            1. Create a table named "Movie" in the "VideoStore" database on Azure
            2. Read data from "Movie.txt" and insert them into "Movie".
               * Columns are separated by '|'
               * You can use executemany() to insert multiple rows in bulk
    """
    #WRITE YOUR CODE HERE
    
    cursor = conn.cursor()

    cursor.execute("""CREATE TABLE Movie(
                mid INTEGER PRIMARY KEY,
                mname VARCHAR(50),
                year INTEGER
                )""")

    file = open(filename, "r")
    num_of_lines =  file.readlines()

    inputs = []

    for l in num_of_lines:
        mid,mname,year = l.strip().split('|')
        input = (mid,mname,year)
        inputs.append(input)
    
    file.close()
    cursor.executemany("INSERT INTO Movie Values (?,?,?)", inputs)
    conn.commit()
    

def loadRental(filename, conn):
    """
        Input:
            $filename: "Rental.txt"
            $conn: you can get it by calling connect_db()
        Functionality:
            1. Create a table named "Rental" in the VideoStore database on Azure
            2. Read data from "Rental.txt" and insert them into "Rental".
               * Columns are separated by '|'
               * You can use executemany() to insert multiple rows in bulk
    """
    #WRITE YOUR CODE HERE
    
    cursor = conn.cursor()

    cursor.execute("""CREATE TABLE Rental(
                cid INTEGER FOREIGN KEY REFERENCES Customer(cid) on DELETE CASCADE,
                mid INTEGER FOREIGN KEY REFERENCES Movie(mid) on DELETE CASCADE,
                date_and_time DATETIME,
                status VARCHAR(6)
                )""")

    file = open(filename, "r")
    num_of_lines =  file.readlines()

    inputs = []

    for l in num_of_lines:
        cid,mid,date_and_time,status = l.strip().split('|')
        input = (cid,mid,date_and_time,status)
        inputs.append(input)
    
    file.close()
    cursor.executemany("INSERT INTO Rental Values (?,?,?,?)", inputs)
    conn.commit()


def dropTables(conn):
    conn.execute("DROP TABLE IF EXISTS Rental")
    conn.execute("DROP TABLE IF EXISTS Customer")
    conn.execute("DROP TABLE IF EXISTS RentalPlan")
    conn.execute("DROP TABLE IF EXISTS Movie")


if __name__ == "__main__":
    conn = connect_db()

    dropTables(conn)

    loadRentalPlan("RentalPlan.txt", conn)
    loadCustomer("Customer.txt", conn)
    loadMovie("Movie.txt", conn)
    loadRental("Rental.txt", conn)


    conn.commit()
    conn.close()






