# checking cycle using dfs in ***CONNECTED GRAPH***
# if we come across a node which is already in the recusrion stack means some node redirects back to its ancestor node
# which means there is a cycle

# representing using adjacency list 

from collections import defaultdict
class graph(object):
	"""docstring for graph"""
	def __init__(self):
		self.adjl = defaultdict(list)

	def addedge(self,u,v): self.adjl[u].append(v) 

	def iscycle(self, vis, recusrion_stack, vertex):
		vis[vertex] = recusrion_stack[vertex] = True
		for v in self.adjl[vertex]:
			if not vis[v]:
				if self.iscycle(vis, recusrion_stack, v):
					return True
			elif recusrion_stack[vertex]:
				return True

		recusrion_stack[vertex]= False
		return False

	def check_cycle(self,source):
		vis = [True]*len(self.adjl)
		recusrion_stack = [True]*len(self.adjl) 
		return self.iscycle(vis, recusrion_stack, source)

if __name__ == '__main__':
	g = graph()
	g.addedge(0,1)
	g.addedge(0,2)
	g.addedge(1,2)
	g.addedge(2,0)
	g.addedge(2,3)
	g.addedge(3,3)

	print(g.check_cycle(0))