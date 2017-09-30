class Base1(object):
    def __init__(self):
        self.str1 = "Geek1"
        self.x1=100
        print("Base1", self.x1)
 
class Base2(object):
    def __init__(self):
        self.str2 = "Geek2"       
        self.x2=200
        print("Base2", self.x2)
 
class Derived(Base1, Base2):
    def __init__(self):
         
        # Calling constructors of Base1
        # and Base2 classes
        Base1.__init__(self)
        Base2.__init__(self)
        self.x1=10
        self.x2=20
        print("Derived")
         
    def printStrs(self):
        print(self.str1, self.str2)
        print(self.x1, self.x2)
        
 
ob = Derived()
ob.printStrs()
print(issubclass(Derived, Base1))
print(issubclass(Derived, Base2))
print(isinstance(ob, Base1))
print(isinstance(ob, Base2))
print(isinstance(ob, Derived))
