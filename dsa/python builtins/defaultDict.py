#default dict is a dictionary which assumes some default value for unknown keys
from collections import defaultdict
d = defaultdict(list) #default value set to an empty list
#the argument passed must be a function
# d[2]=4
# d[3]=6
# print(d[5])

# -------------------implementing using simple dict-------------------
class default_dict(dict):
 	"""docstring for default_dict"""
 	def __init__(self, arg):
 		super().__init__()
 		self.func= arg 
 	def __missing__(self, arg):
 		self[arg] =val = self.func()
 		return val

# dd=default_dict(list)
# dd[1]=7
# print(dd,dd[9])


 	
