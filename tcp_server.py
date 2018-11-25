
#! /usr/bin/env python3
# coding = utf-8

'''
@author: yeqinlao
'''

#这个脚本创建一个tcp服务器，他接受来自客户端的消息，并返回了加时间戳的相同消息

from socket import *
from time import ctime

HOST = '127.0.0.1'
PORT = 21567
BUFSIZ = 1024
ADDR = (HOST, PORT)

tcpSersock = socket(AF_INET, SOCK_STREAM)
tcpSersock.bind(ADDR)
tcpSersock.listen(5)

while True:
        print('waiting for connection...')
        tcpCliSock, addr = tcpSersock.accept()
        print('...connected from:', addr)

        while True:
                data = tcpCliSock.recv(BUFSIZ)
                if not data:
                        break
                tcpCliSock.send((bytes(ctime() + ": ", 'utf-8') + data))
        tcpCliSock.close()
tcpSersock.close()
