class TestMethod(object):
     class_property = "class property"
     def __init__(self):
         self.instance_property = "instance property"
     def instance_method(self, arvg):
         print "instance_method(%s, %s)" % (self, arvg)
         print "instance property: ", self.instance_property
     @classmethod
     def class_method(cls, arvg):
         print "class_method(%s, %s)" % (cls, arvg)
         print "class property: ", cls.class_property
     @staticmethod
     def static_method(arvg):
         print "static_method(%s)" % arvg

test_method = TestMethod()
test_method.instance_method("Hello")

test_method.class_method("Hello")

test_method.static_method("Hello")

TestMethod.static_method("Hello")
