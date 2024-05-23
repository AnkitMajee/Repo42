import socket

# Host and port configuration
HOST = '0.0.0.0'  # Listen on all available network interfaces
PORT = 8080       # Port number to bind the server to
MAX_MSG_SIZE = 1024  # Maximum message size for receiving data

# Create a socket object
# srv_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# AF_INET stands for "Address Family: Internet". This indicates that the socket will use the IPv4 protocol. If you wanted to use IPv6, you would use AF_INET6 instead.
# Bind the socket to the specified host and port
srv_sock.bind((HOST, PORT))
# Set the socket to listen for incoming connections, with a maximum backlog of 3 connections
srv_sock.listen(3)

# Accept a connection from a client
cli_sock, client_address = srv_sock.accept()

# Start an infinite loop to handle the client connection
while True:
    # Receive data from the client, up to the maximum message size
    data = cli_sock.recv(MAX_MSG_SIZE)
    # If no data is received, the client has disconnected
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
    cli_sock.send(data.encode('utf-8'))
    # Print the echoed data
    print("Echoed back:", data, end='')
    # If the echoed data does not end with a newline character, print a newline
    if data[-1] != '\n': 
        print()

# Close the client socket
cli_sock.close()
# Close the server socket
srv_sock.close()


''' OUTPUT:
# server output
Received: hi
Echoed back: hi
Received: hello
Echoed back: hello
Received: hello there!
Echoed back: hello there!
Received: general kenobi!
Echoed back: general kenobi!
Client disconnected

# client output
$ nc localhost 8080
hi
hi
hello
hello
hello there!
hello there!
general kenobi!
general kenobi!
^C
'''
