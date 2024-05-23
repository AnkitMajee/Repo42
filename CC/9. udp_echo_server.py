import socket

# Host and port configuration
HOST = '0.0.0.0'  # Listen on all available network interfaces
PORT = 8080       # Port number to bind the server to
MAX_MSG_SIZE = 1024  # Maximum message size for receiving data

# Create a socket object for UDP
srv_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# Bind the socket to the specified host and port
srv_sock.bind((HOST, PORT))

# Start an infinite loop to handle incoming messages
while True:
    # Receive data from a client, along with the client's address
    data, client_address = srv_sock.recvfrom(MAX_MSG_SIZE)
    # Check if no data is received
    if not data:
        print("Client disconnected")
        break

    # Decode the received bytes into a string using UTF-8 encoding
    data = data.decode('utf-8')
    # Print the received data
    print("Received:", data, end='')
    # If the received data does not end with a newline character, print a newline
    if data[-1] != '\n': 
        print()

    # Send the received data back to the client (echo it back)
    srv_sock.sendto(data.encode('utf-8'), client_address)
    # Print the echoed data
    print("Echoed back:", data, end='')
    # If the echoed data does not end with a newline character, print a newline
    if data[-1] != '\n': 
        print()

# Close the server socket
srv_sock.close()


''' OUTPUT:
# server output
Received: hi
Echoed back: hi
Received: hello
Echoed back: hello
^C

# client output
$ nc -u localhost 8080
hi
hi
hello
hello
^C
'''
