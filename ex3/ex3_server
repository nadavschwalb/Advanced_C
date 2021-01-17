#!/usr/bin/env python2.7 -tt
import socket
import sys

#vars and consts
error_msg = "HTTP/1.1 404 Not Found\r\n\
Content-type: text/html\r\n\
Content-length: 113\r\n\
\r\n\
<html><head><title>Not Found</title></head><body>\r\n\
Sorry, the object you requested was not found.\r\n\
</body></html>\r\n\r\n"

BUFF_LENGTH =1024
HOST = '127.0.0.1'  # The server's hostname or IP address
recv_data = ''
msg = ''
counter = 0 


port = int(sys.argv[1])
print(port)
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((HOST,port))
while(True):
  while(True):
    recv_data += str(s.recv(BUFF_LENGTH).decode("utf-8"))
    if '\r\n\r\n' in recv_data:
      break

  data_lines = recv_data.split("\r\n")
  if "GET /counter" in data_lines[0]:
    counter += 1
    msg = "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\nContent-Length:\
     {}\r\n\r\n{}\r\n\r\n".format(len(str(counter)),counter)
  else:
    msg = error_msg
  s.sendall(bytes(msg))
  print(counter)
  recv_data = ''

#print(recv_data)