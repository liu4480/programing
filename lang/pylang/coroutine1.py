#! /usr/bin/python3
# coroutine execution
 
def print_name(prefix):
    print("Searching prefix:{}".format(prefix))
    try:
        while True:
            name = (yield)
            if prefix in name:
                print(name)
    except GeneratorExit as err:
        print("Closing coroutine!!")
        print(err)
# calling coroutine, nothing will happen
corou = print_name("Dear")
 
# This will start execution of coroutine and 
# Prints first line "Searchig prefix..."
# and advance execution to the first yield expression
corou.next()
#corou.__next__() #in my os, this reported generator has no __next__
 
# sending inputs
corou.send("Atul")
corou.send("Dear Atul")
