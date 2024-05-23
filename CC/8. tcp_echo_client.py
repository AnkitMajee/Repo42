import socket

# Host and port configuration
HOST = 'localhost'  # The server's hostname or IP address
PORT = 8080         # The port used by the server
MAX_MSG_SIZE = 1024  # Maximum message size for receiving data

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#AF_INET stands for "Address Family: Internet". This indicates that the socket will use the IPv4 protocol. If you wanted to use IPv6, you would use AF_INET6 instead.
#SOCK_STREAM indicates that the socket will be a TCP socket. If you wanted to use a UDP socket, you would use SOCK_DGRAM instead.

# Connect to the server
client_socket.connect((HOST, PORT))

# Start an infinite loop to interact with the server
while True:
    # Get user input for the message to send
    message = input("Send msg (or 'exit' to quit): ")
    # Check for exit command
    if message == 'exit': 
        break
    # Send the message to the server, encoded as UTF-8
    client_socket.send(message.encode('utf-8'))
    # Receive the response from the server
    data = client_socket.recv(MAX_MSG_SIZE)
    # Print the echoed message from the server, decoded from UTF-8
    print("Received:", data.decode('utf-8'))

# Close the client socket
client_socket.close()


''' OUTPUT:
Send msg (or 'exit' to quit): hi
Received: hi
Send msg (or 'exit' to quit): hello
Received: hello
Send msg (or 'exit' to quit): hello there!
Received: hello there!
Send msg (or 'exit' to quit): general kenobi!
Received: general kenobi!
Send msg (or 'exit' to quit): exit
'''