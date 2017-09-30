import time
import requests

def RTT(url):
    t1 = time.time()
    r = requests.get(url)
    t2 = time.time()

    print("time in seconds :", t2 - t1)

url="http://www.google.com"
RTT(url)
