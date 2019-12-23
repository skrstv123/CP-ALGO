#objects can be used in the same way as we use a dictionary, but later is more efficient 
#almost every lookup like tasks possible with objects can be implemented using dictionaries

class dictionary(object):
	"""docstring for dictionary"""
	def __init__(self): pass 

# d=dictionary()
# d.x=0
# d.y=1 
# print(d.__dict__) #objects actually stores every attributes in a dictionary

#----------using __getitem__ -----------------------
# it defines action for object[key] 
# __getattr__ defines response for an attribute call
class someName(object):
	"""docstring for someName"""
	def __init__(self, arg):
		super(someName, self).__init__()
		self.arg = arg
	def __getitem__(self, key):
		return self.__dict__[key]

# a = someName(1)
# a.x=10
# a.y=5
# print(a['x'],a['y'],a['arg'])		

#-------------chaining in classes----------------------
class baseA(object):
	"""docstring for base"""
	x=10

class baseB(object):
	"""docstring for baseB"""
	x,y = 20,30

class inherited(baseA, baseB):
	"""docstring for inherited"""
	pass
		
# d = inherited()
# print(d.x) #d is of class inherited, attribute x is first looked up in inherited then baseA then in baseB hence 10 is returned
# #we're looking up in baseA first then in baseB: so priority is given to the left argument and there should be no confusion as in c++ 

#-----above functionality can be implemented using dictionaries-------
from collections import ChainMap
basea = {'x':10}
baseb = {'x':20,'y':30}

inheriteD = ChainMap({}, basea, baseb)
#creates an empty dictionary linked to basea & baseb

# print(inheriteD['x'],inheriteD['y'])

#------creating this chained dictionary using the class's definition--------------
# __mro__ returns the parent class(es)
#print(inherited.__mro__)
INherited = ChainMap({},*(base.__dict__ for base in inherited.__mro__))
#print(INherited['x'])


#----------live attributes---------------
#generally the attributes are just some values, but we can mark a method too as an attribue using the @property decorator

class alive(object):
  	"""docstring for alive"""
  	def __init__(self, x):
  		super(alive, self).__init__()
  		self._x = x 

  	@property
  	def x(self):
  		self._x += 1
  		return self._x
  	
# obj = alive(7)
# print(obj.x,obj.x,obj.x)

#--------live attributes using __getitem__ ------------
class live(object):
	"""docstring for live"""
	def __init__(self, x):
		super(live, self).__init__()
		self._x = x

	def __getitem__(self, key):
		if key == 'x':
			self._x+=1 
			return self._x
		raise KeyError('invalid key!')

# obj = live(10)
# print(obj['x'],obj['x'],obj['x'])

#------------------Attribute Dictionary----------------
class attrDict(dict):
	"""docstring for attrDict"""
	def __init__(self, *args, **kwargs):
		super(attrDict, self).__init__( *args, **kwargs)
		self.__dict__= self 
		#__dict__ contains attributes and we're assigning our dictionary to the attr dictionary
		# so , obj[key] should be same as obj.key
		#this definition is similar to js's objects
