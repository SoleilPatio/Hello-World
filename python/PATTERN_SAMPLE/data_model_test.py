
import sys

class FooObj(object):
    
    """
    Basic
    """
    def __init__(self):
        if sys.version_info[0] == 3:
            #Python 3
            super().__init__()
        else:
            #Python 2 : super return super class of FooObj
            super(FooObj, self).__init__()
        
        
        print "[constructor]"
        self.test_dict = {
                      "A":111,
                      "B":222,
                      "C":333
                      }
        pass
    
    def __del__(self):
        print "[destructor]"
        pass
    
    #call by str()
    def __str__(self):
        return "__str__"
    
    #call when print in list of object,instead of __main__.Test instance at 0x00CBC1E8 ...etc..
    def __repr__(self):
        return "%s"%self.__dict__
    
    """
    Emulating container types
    """
    #FooObj[index]
    def __getitem__(self,key):
        print "[__getitem__]"
        return self.test_dict[key]
    
    def __setitem__(self, key, value):
        print "[__setitem__]"
        self.test_dict[key] = value
        return self.test_dict[key]
        
    
    def __missing__(self, key):
        print "[__missing__]"
        return None
    
    def __len__(self):
        return len(self.test_dict)
    
    def __delitem__(self, key):
        pass
    
    #test operators (in and not in)
    def __contains__(self, item):
        print "[__contains__]"
        return item in self.test_dict
    
    
    """
    With Statement Context Managers
    """
    def __enter__(self):
        print "[__enter__]"
        pass
    
    def __exit__(self, exc_type, exc_value, traceback):
        print "[__exit__]"
        pass
    
    




if __name__ == '__main__':
    
    foo = FooObj()
    
    key = "A"
    if key in foo:
        print "yes"
    
    print foo["A"]
    print foo["Z"] if "Z" in foo else "not in"
    
    foo["A"] = 999
    print foo["A"]
    
    
    pass