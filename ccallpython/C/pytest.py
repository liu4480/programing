def add(a, b):
    print "in python function add"
    print "a = " + str(a)
    print "b = " + str(b)
    print "ret = " + str(a+b)
    return a + b

def foo(a, b):
    print "in python fnction foo"
    print "a = " + str(a)
    print "ret = " + str(a*a)
    return a*a

class guestList:
    def __init__(self):
        print 'aaaaaaaaaa'

    def p():
        print 'bbbbbbbbbb'

    def __getitem__(self, id):
        return 'cccccccccc'

def update():
    guest = guestList()
    print guest['aa']
