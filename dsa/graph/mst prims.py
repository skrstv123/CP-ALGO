# minimum spanning tree using prims algorithm
from sys import maxsize 

# representing using adjacency list 

from collections import defaultdict
class graph(object):
	"""docstring for graph"""
	def __init__(self,vc):
		self.vcount = vc
		self.adjl = defaultdict(list)

	def addEdge(self,u,v,w): 
		self.adjl[u].append([v,w]) 

	def min_weight(self,key,mst):
		 cmin = minin =  maxsize
		 for v in range(self.vcount): # skipping source node
		 	if key[v]< cmin and not mst[v]:
		 		cmin = key[v]
		 		minin = v 
		 return minin

	def mst_prim(self):

		adj_mat = [[0]*self.vcount for _ in range(self.vcount)]
		for r in self.adjl:
			for c in self.adjl[r]:
				adj_mat[r][c[0]] = adj_mat[c[0]][r] = c[-1]
		# print(adj_mat)

		key = [maxsize]*self.vcount # to store weights
		parent  = [-maxsize]*self.vcount #to store parent vertex

		#make a mst marker to mark a node is included in mst
		mst = [False]*self.vcount

		# make a source vertex by making its weight 0
		key[0] = 0
		# also mark its parent as source by making it -1
		parent[0] = -1

		for ver in range(self.vcount):

			# find min weight not yet included in the mst
			a = self.min_weight(key, mst)

			# add it to mst
			mst[a] = True

			for v in range(self.vcount):
				# zero value in graph means no edge is there
				# update key if weight a to v < current weight at v
				if adj_mat[a][v] > 0 and mst[v]==False and adj_mat[a][v] < key[v]:
					key[v] = adj_mat[a][v]
					parent[v] = a

		for i in range(1,self.vcount):
			print(parent[i],'--',i,':',adj_mat[i][parent[i]])

g = graph(4) 
g.addEdge(0, 1, 10) 
g.addEdge(0, 2, 6) 
g.addEdge(0, 3, 5) 
g.addEdge(1, 3, 15) 
g.addEdge(2, 3, 4) 
  
g.mst_prim()