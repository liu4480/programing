#! /usr/bin/python3

import secrets

#this function is responsible for generating a random byte string containing
#nbytes number of bytes. if no value is provided, the reasonable default is used
token1 = secrets.token_bytes()
token2 = secrets.token_bytes(10)

print(token1)
print(token2)

#this function is responsible for generating a random text string in hexadecimal
#containing nbytes random bytes. if no value is provided, a reasonable default is used
token1 = secrets.token_hex(16)
token2 = secrets.token_hex(9)
 
print(token1)
print(token2)

#This function is responsible for generating a random URL-safe text string containing
#nbytes random bytes. This is suitable for password recovery applications.
url = 'https://mydomain.com/reset=' + secrets.token_urlsafe()
print(url)
