import socket
import random
import math

def isPrime(num):
    for n in range (num):
        if(n>1):
            if num%n ==0:
                return False
    return True
def gcd(x,y):
    z= 1
    for i in range(3,min(x,y)):
        if(x%i==0 and y%i ==0 ):
            z = i
    return z
def getE(phi):
    e  = random.randrange(3,phi,2)
    if(math.gcd(phi,e)==1):
        return e
    else:
        return getE(phi)

def generateKeys():
    q = random.randint(3,100)
    p = random.randint(3,100)


    if(isPrime(p) and isPrime(q)):
        return (p,q)
    else:
        return generateKeys()

def preperations():
    p, q = generateKeys()

    n = p * q
    phi = (q - 1) * (p - 1)
    k =2
    e = getE(phi)
    d = ( k*(phi) + 1) / e
    if not(d%1==0) or not (d%e==1):
        return preperations()
    else:
        d = int(d)
        print(f"{q} is Q and {p} is P")
        return e,d,n,phi

def decyrypt(C, d,n):
    return (C**d)%n

def main():
    #preparations
    e,d,n,phi = preperations()

    print(f"**** {n} IS n VALUE , {phi} IS phi VALUE, {e} IS e VALUE , {d} IS D VALUE*****")

    #server setup
    PORT = 9000
    SERVER = socket.gethostbyname(socket.gethostname())
    ADDR = (SERVER, PORT)
    server = socket.socket()
    server.bind((ADDR))
    server.listen()
    
    #decrypting and sending the decrypted answer
    conn, addr = server.accept()
    if conn:
        str_n = str(n)
        str_e = str(e)
        conn.send(str_n.encode())
        conn.send(str_e.encode())

    while True:
        encrypted_msg = int(conn.recv(1024).decode())

        if(encrypted_msg == 270): #C when char is p (p for pause)
            break
        msg = decyrypt(encrypted_msg,d,n)
        conn.send(str(msg).encode())
    conn.close()
    server.close()
    
    


if __name__ == "__main__":
    main()
