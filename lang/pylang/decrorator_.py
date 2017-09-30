#! /usr/bin/python3

def messageWithWelcome(str):
    def addWelcome():
        return "welcome to "

    return addWelcome() + str

def site(site_name):
    return site_name

print(messageWithWelcome(site("GeeksforGeeks")))

def decorate_message(fun):
 
    # Nested function
    def addWelcome(site_name):
        return "Welcome to " + fun(site_name)
 
    # Decorator returns a function
    return addWelcome
 
@decorate_message
def site(site_name):
    return site_name;
 
# Driver code
 
# This call is equivalent to call to
# decorate_message() with function
# site("GeeksforGeeks") as parameter
print(site("GeeksforGeeks"))

# A decorator function to attach
# data to func
def attach_data(func):
       func.data = 3
       return func
 
@attach_data
def add (x, y):
       return x + y
 
# Driver code
 
# This call is equivalent to attach_data()
# with add() as parameter
print(add(2, 3))
 
print(add.data)
