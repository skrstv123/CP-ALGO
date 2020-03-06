# checking for cycle in graph using union-find algorithm
# representing using adjacency list 

from collections import defaultdict, deque
class graph(object):
	"""docstring for graph"""
	def __init__(self,vertices):
		self.adjl = defaultdict(list)
		self.vcount = vertices

	def addedge(self,u,v): self.adjl[u].append(v) 

	# union find algorithm
	# finding parent set
	def find_set(self, parent, i):
		return i if parent[i]==None else self.find_set(parent,parent[i])

	def make_union(self, parent, a, b):
		seta = self.find_set(parent, a)
		setb = self.find_set(parent, b)
		parent[seta] = setb

	def check_cycle(self):

		parent = [None]*self.vcount 

		for i in self.adjl:
			# go through each adjacent node 
			# adjacent node means we're processing an edge
			for j in self.adjl[i]:
				a = self.find_set(parent, i)
				b = self.find_set(parent, j)
				# there's a cycle if both are already in same set
				if a==b : return True
				self.make_union(parent, a, b)

g = graph(3) 
g.addedge(0, 1) 
g.addedge(1, 2) 
g.addedge(2, 0) 
print(g.check_cycle())