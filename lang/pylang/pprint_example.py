#! /usr/bin/python3

# A python code with pprint
import requests
from pprint import pprint
 
def geocode(address):
    url = "https://maps.googleapis.com/maps/api/geocode/json"
    resp = requests.get(url, params = {'address': address})
    return resp.json()
 
# calling geocode function
data = geocode('India gate')
 
# pretty-printing json response
print("calling print function:")
print(data)
print("\n\n\n")
print("calling pprint function:")
pprint(data)
