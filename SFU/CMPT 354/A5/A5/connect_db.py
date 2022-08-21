import pyodbc


def connect_db():
    ODBC_STR = "Driver={ODBC Driver 17 for SQL Server};Server=tcp:jada5.database.windows.net,1433;Database=VideoStore;Uid=jad;Pwd={U34A6GLeWR83wrd};Encrypt=yes;TrustServerCertificate=no;Connection Timeout=30;"
    return pyodbc.connect(ODBC_STR)


if __name__ == '__main__':
    print(pyodbc.drivers())
    print(connect_db())
