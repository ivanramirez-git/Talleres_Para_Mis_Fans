import pymysql
from config import DevelomentConfig


def mysqlconnect():
    # To connect MySQL database
    conn = pymysql.connect(
        host=DevelomentConfig.MYSQL_HOST,
        user=DevelomentConfig.MYSQL_USER,
        password=DevelomentConfig.MYSQL_PASSWORD,
        db=DevelomentConfig.MYSQL_DB,
    )

    cur = conn.cursor()
    cur.execute("select @@version")
    output = cur.fetchall()
    # print(output)

    # To close the connection
    conn.close()


# Driver Code
if __name__ == "__main__":
    mysqlconnect()
