#! /usr/bin/python3
# Python code to demonstrate working of
# str() and items()
import  copy

# Initializing dictionary
dic = { 'Name' : 'Nandini', 'Age' : 19 }
 
# using str() to display dic as string
print ("The constituents of dictionary as string are : ")
print (str(dic))
 
# using str() to display dic as list
print ("The constituents of dictionary as list are : ")
print (dic.items())
for key, value in dic.items():
    print(key, value)

print("len(dic)=", len(dic))
print("type(dic)=", type(dic))

dic1 = {"Name" : "Nandini", "Age" : 19}
dic2 = {}
dic3 = {}
dic2 = copy.deepcopy(dic1)
dic3 = dic1.copy()

print(id(dic1))
print(id(dic2))
print(id(dic3))
print(id(dic1.items()))
print(id(dic2.items()))

# Initializing dictionary 1
dic1 = { 'Name' : 'Nandini', 'Age' : 19 }
 
# Initializing dictionary 2
dic2 = { 'ID' : 2541997 }
 
# Initializing sequence
sequ = ('Name', 'Age', 'ID')
 
# using update to add dic2 values in dic 1
dic1.update(dic2)
 
# printing updated dictionary values
print ("The updated dictionary is : ")
print (str(dic1))
 
# using fromkeys() to transform sequence into dictionary
dict = dict.fromkeys(sequ,5)
 
# printing new dictionary values
print ("The new dictionary values are : ")
print (str(dict))

dict = { 'Name' : 'Nandini', 'Age' : 19 }
 
# using has_key() to check if dic1 has a key
if 'Name' in dict.keys():
       print ("Name is a key")
else : print ("Name is not a key")
 
# using get() to print a key value
print ("The value associated with ID is : ")
print (dict.get('ID', "Not Present"))
 
# printing dictionary values
print ("The dictionary values are : ")
print (str(dict))

# Initializing dictionary
dict = { 'Name' : 'Nandini', 'Age' : 19 }
 
# using setdefault() to print a key value
print ("The value associated with Age is : ",end="")
print (dict.setdefault('ID', "No ID"))
 
# printing dictionary values
print ("The dictionary values are : ")
print (str(dict))
print(id(dic3.items()))
