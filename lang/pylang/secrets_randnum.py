#! /usr/bin/python3

import secrets
import string

alphabet = string.ascii_letters + string.digits

password = ''.join(secrets.choice(alphabet) for i in range(10))

print(password)

#generate password which has at least one lower character, one upper character, and at least 3 digits 
while True:
    password = ''.join(secrets.choice(alphabet) for i in range(10))
    if (any(c.islower() for c in password) and any(c.issupper() for c in password) and sum(c.isdigit() for c in password &gt;=3):
            print(password)
            break

#return a random integer in range[0, n)
print(secrets.randbelow(20))

#return an integer with k random bits
print(secrets.randbits(7))
