# single source shortest path - BellmanFord
# calculates the minimum distance from a source to every other vertex

from collections import defaultdict
maxsize = float('Inf')


class graph:

    def __init__(self, vc):
        self.vcount = vc
        self.adjl = defaultdict(list)

    def addEdge(self,u,v,w):
        self.adjl[u].append([v, w])

    def sssp_bellmanFord(self, src):
        edges = []
        for v in self.adjl:
            for e in self.adjl[v]:
                edges.append([v] + e)

        dist = [maxsize] * self.vcount
        dist[src] = 0

        for runs in range(self.vcount - 1):
            for (u, v, w) in edges:
                if dist[u]!=maxsize and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

        # negative loop check
        # as only v-1 runs are required to find all shortest paths
        # if any further optimization occurs in vth run then there is a -ve loop

        for (u, v, w) in edges:
            if dist[u] + w < dist[v]:
                print('Negative cycle exists!')

        # result
        for res in range(self.vcount):
            print(src, '-->', res, ':', dist[res])

# -------------------------------------------------------------
g = graph(5)
g.addEdge(0, 1, -1) 
g.addEdge(0, 2, 4) 
g.addEdge(1, 2, 3) 
g.addEdge(1, 3, 2) 
g.addEdge(1, 4, 2) 
g.addEdge(3, 2, 5) 
g.addEdge(3, 1, 1) 
g.addEdge(4, 3, -3) 
  

g.sssp_bellmanFord(src=0)
			
