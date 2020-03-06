# single source shortest path - Dijkstra
# calculates the minimum distance from a source to every other vertex
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

	def find_min(self,distances, included_vertices):

		min_vertex =min_index= maxsize 
		for v in range(self.vcount):
			if distances[v] < min_vertex and included_vertices[v]==0:
				min_vertex = distances[v]
				min_index = v 
		return min_index

	def sssp_dijkstra(self,src=0):
		# creating adjacency matrix from adjacency list 
		adj_mat = [[0]*self.vcount for _ in range(self.vcount)]
		for v in self.adjl:
			for ertex in self.adjl[v]:
				# assuming undirected graph
				adj_mat[v][ertex[0]] = adj_mat[ertex[0]][v] = ertex[-1]


		# initialize distance of each vertex as infinity
		dist = [maxsize]*self.vcount 
		# make source distance 0
		dist[src] = 0
		# make a vertex marker for vertices included in shortest path
		vertex_marker = [0]*self.vcount

		for each_vertex in range(self.vcount):

			# pick the one with minimum weight which isnt yet included in shortest path
			# use this as parent node
			u = self.find_min(dist, vertex_marker)

			# include it in shortest path
			vertex_marker[u] = 1 

			# for all adjacent vertices of u not yet marked, update distance if new distance is shorter 
			for neighbour in range(self.vcount):
				if adj_mat[u][neighbour]>0 and vertex_marker[neighbour]==0:
					if dist[u] + adj_mat[u][neighbour] < dist[neighbour]:
						dist[neighbour] = dist[u] + adj_mat[u][neighbour]
						

		# printing minimum distances 
		for vertex in range(self.vcount):
			print(src,'-->',vertex,':',dist[vertex])

g = graph(9)
g.addEdge(0,1,4)
g.addEdge(1,2,8)
g.addEdge(2,3,7)
g.addEdge(3,4,9)
g.addEdge(4,5,10)
g.addEdge(3,5,14)
g.addEdge(2,5,4)
g.addEdge(6,5,2)
g.addEdge(2,8,2)
g.addEdge(8,6,6)
g.addEdge(7,6,1)
g.addEdge(7,8,7)
g.addEdge(1,7,11)
g.addEdge(0,7,8)

g.sssp_dijkstra(src=0)