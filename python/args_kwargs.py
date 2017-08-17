def testify(arg1, *argv):
    print "first argument :", arg1
    for arg in argv:
        print "Next argument through *argv :", arg
 
testify('Hello', 'Welcome', 'to', 'GeeksforGeeks')

def hello(**kwargs):
    if kwargs is not None:
        for key, value in kwargs.iteritems():
            print "%s == %s" %(key, value)

hello(name="GeeksforGeeks", id1=100, nation="CN")
