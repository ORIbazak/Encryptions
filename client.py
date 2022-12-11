import socket
import math

def encrypt(e,n , m):
    return((m**e)%n)

def main():

    PORT = 9000
    SERVER = socket.gethostbyname(socket.gethostname())
    ADDR = (SERVER, PORT)





    client = socket.socket()
    client.connect((ADDR))
    n = int(client.recv(1024).decode())
    e =int(client.recv(1024).decode())
    msg = input("****ENTER CHAR*****")
    number = ord(msg)
    while(msg != "p" ):
        msg = int(encrypt(e,n,number))
        client.send(str(msg).encode())
        sent_back = int(client.recv(1024).decode())
        orig = chr(sent_back)
        print(f"****YOUR CHAR IS: {orig} *****")
        msg = input("****ENTER CHAR*****")
        number = ord(msg)
   


    
    
    





if __name__ == "__main__":
    main()
