# representing using adjacency list 

from collections import defaultdict
class graph(object):
	"""docstring for graph"""
	def __init__(self,vc):
		self.adjl = defaultdict(list)
		self.vcount = vc

	def addEdge(self,u,v,w): 
		self.adjl[u].append([v,w]) 

	#<---------union-find algorithm---------------->
	def find_set(self, parent, i):
		return i if parent[i]==None else self.find_set(parent,parent[i])

	def make_union(self, parent, a, b):
		seta = self.find_set(parent, a)
		setb = self.find_set(parent, b)
		parent[seta] = setb

	#</---------union-find algorithm---------------->

	def mst_kkl(self):
		edges= []
		for i in self.adjl:
			for j in self.adjl[i]:
				# u, v, weight
				edges.append([i,j[0],j[1]])
		edges.sort(key = lambda x: x[2])

		parent = [None]*self.vcount

		e=1
		result = []
		while e<self.vcount: # in a tree of n nodes there are n-1 edges
			u,v,w = edges.pop(0)
			x = self.find_set(parent, u)
			y = self.find_set(parent, v)

			if x!=y: # if not in same set/ if not forming a cycle
				e+=1 
				result.append([u,v,w])
				self.make_union(parent,x,y)
		total= 0
		for r in result:
			print(r[0],'--',r[1],':',r[-1])
			total+=r[-1]
		print('total weight:',total)



g = graph(4) 
g.addEdge(0, 1, 10) 
g.addEdge(0, 2, 6) 
g.addEdge(0, 3, 5) 
g.addEdge(1, 3, 15) 
g.addEdge(2, 3, 4) 
  
g.mst_kkl()