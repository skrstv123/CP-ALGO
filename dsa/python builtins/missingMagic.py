#applications of __missing__ func 
#__missing__ # this function is called whenever a key is not found in the dictionary 


#--------------------implementing smart functions-----------------------------------
# __missing__ can be redefined to implement any function as a dictionary
#it is always better to use dictionaries as function definitions as it avoids recomputation

#demo: implementing pythagoras theorem
#1 using func 
def pythagoras(a,b):
	from math import sqrt
	return sqrt(a**2 + b**2) 

#2 by modified dictionary
class pythagoras_dict(dict):
	"""docstring for pythagoras_dict"""
	def __missing__(self, arg):
		from math import sqrt 
		a,b = arg
		self[arg] = val =  sqrt(a**2 + b**2) 
		return val
# driver code
# fpy=pythagoras(2,4)
# dpy=pythagoras_dict()
# dpyval=dpy[2,4]
# print(fpy , dpyval, dpy)		

#---------------------implementing memoisation class-----------------------------
from inspect import signature


class memoise(dict):

    def __init__(self, func):
        self.func = func
        self.signature = signature(func)

    def __missing__(self, key):
        (arg, kwarg) = key
        self[key] = val = self.func(*arg, **dict(kwarg))
        return val

    def __call__(self, *arg, **kwarg):
        key = self.signature.bind(*arg, **kwarg)
        return self[key.args, frozenset(key.kwargs.items())]


@memoise 
def fib(a):
    #try this function with and without the decorator :)
    if a<=1:
        return 1 
    return fib(a-1)+fib(a-2)

#print(fib(40))

#-------------------------implementing the range dictionary-------------------------------------
# key is a range, all values in this range are mapped to the corresponding value

from collections import Iterable
class rangedict(dict):
	"""docstring for rangedict"""
	def __missing__(self, key):
		for k,v in self.items():
			if isinstance(k , Iterable): #check if range like key available
				l,r=k 
				if l<= key< r:
					self[key] = v #store this point as another key,val pair to avoid recomputation
					return v 
		raise KeyError('not in any range') 

#driver code
# ccodes = rangedict({(0,40):'red',(41,88):'blue'})
# print(ccodes[31])

#-------------------implementing censored text converter------------------------------
# ex: i/p: 'fack off' ; o/p: 'f**k off'

class censor_dict(dict):
	"""modified to return the key itself in case it is not there in the dictionary"""
	def __missing__(self, key):
		return key 
# censored = censor_dict({'fack':'f**k','cool':'python :p'}) 
# txt = "fack me i'm cool"
# txt = ' '.join(censored[x] for x in txt.split())
# print(txt)
