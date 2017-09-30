def de(f):
    def call_wrapper():
        print '-----------------------------------'
        return f()
    return call_wrapper

@de
def func1():
    print 'I am function func1'.format()

@de
def func2():
    print 'I am function func2'.format()

func1()
func2()

#def p_decorate(func):
#   def func_wrapper():
#       return "<p>{0}</p>".format(func())
#   return func_wrapper
#
#@p_decorate
#def get_text():
#   return "lorem ipsum, dolor sit amet".format()
#
#print get_text()
