#! /usr/bin/python3

import time
import datetime
from datetime import date
 
# using time() to display time since epoch
print ("Seconds elapsed since the epoch are : ",end="")
print (time.time())
 
 
# using gmtime() to return the time attribute structure
print ("Time calculated acc. to given seconds is : ")
print (time.gmtime())

ti=time.gmtime()
print("Time calculated using asctime() is: ", end="")
print(time.asctime(ti))

print("Time calculated using ctime() is: ", end="")
print(time.ctime())
time.sleep(4)
print(time.ctime())

# using MINYEAR to print minimum representable year
print ("Minimum representable year is : ",end="")
print (datetime.MINYEAR)
 
# using MAXYEAR to print maximum representable year
print ("Maximum representable year is : ",end="")
print (datetime.MAXYEAR)

print ("The represented date is : ",end="")
print (datetime.date(1997,4,1))
 
# using today() to print present date
print ("Present date is : ",end="")
print (date.today())

print ("The calculated date from seconds is : ",end="")
print (date.fromtimestamp(934524350))
 
# using min() to print minimum representable date
print ("Minimum representable date is : ",end="")
print (date.min)
 
# using max() to print minimum representable date
print ("Maximum representable date is : ",end="")
print (date.max)
