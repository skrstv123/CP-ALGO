# representing using adjacency list 

from collections import defaultdict, deque
class graph(object):
	"""docstring for graph"""
	def __init__(self):
		self.adjl = defaultdict(list)

	def addedge(self,u,v): self.adjl[u].append(v) 

def bfs(graph, source):
	graph = graph.adjl
	vis = [0]*len(graph)
	queue = deque([])
	queue.append(source)
	vis[source] = 1 
	while queue:
		source = queue.popleft()
		print(source,end = ' ')
		for n in graph[source]:
			if not vis[n]:
				queue.append(n)
				vis[n] = 1 

g = graph()
g.addedge(0,1)
g.addedge(0,2)
g.addedge(1,2)
g.addedge(2,0)
g.addedge(2,3)
g.addedge(3,3)

bfs(g,2)