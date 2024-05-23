import socket

# Port configuration
PORT = 8080  # Port number to bind the server to

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# Bind the socket to all network interfaces and the specified port
sock.bind(('', PORT))

# Print a message indicating the server is listening for messages
print(f"Listening for messages on broadcast port {PORT}...")

# Start an infinite loop to receive and print messages
while True:
    # Receive data from a client, along with the client's address
    data, addr = sock.recvfrom(1024)
    # Print the received data and the address of the sender
    print(f"Received {addr}: {data.decode()}")

# Close the socket (unreachable code in this case as the loop is infinite)
sock.close()


''' OUTPUT:
Listening for messages on broadcast port 8080...
Received ('192.168.83.119', 46743): hi
Received ('192.168.83.119', 46743): hello
Received ('192.168.83.119', 46743): it's alive!
^C
'''
