# single source shortest path unweighted using bfs
# representing using adjacency list 

from collections import deque, defaultdict
class graph(object):
	"""docstring for graph"""
	def __init__(self):
		self.adjl = defaultdict(lambda: {'p':-1,'l':[]})
	def addedge(self,u,v): self.adjl[u]['l'].append(v) 
	def __repr__(self): return str(self.adjl)

def bfs_sssp(graph, source):
	vertex = graph.adjl
	vis = [0]*len(graph.adjl)
	queue = deque([])
	queue.append(source)
	vis[source] = 1 
	while queue:
		source = queue.popleft()
		for n in vertex[source]['l']:
			if not vis[n]:
				vertex[n]['p'] = source
				queue.append(n)
				vis[n] = 1 

g = graph()
g.addedge(0,1)
g.addedge(0,2)
g.addedge(1,2)
g.addedge(2,0)
g.addedge(2,3)
g.addedge(3,3)

bfs_sssp(g,2)
print(g)