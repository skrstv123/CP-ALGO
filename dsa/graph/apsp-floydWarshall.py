# all pair shortest path - Dijkstra
# calculates the minimum distance from every vertex to every another vertex

# representing using adjacency list

from collections import defaultdict


class graph(object):

    """docstring for graph"""

    def __init__(self, vc):
        self.vcount = vc
        self.adjl = defaultdict(list)

    def addEdge(self,u,v,w):
        self.adjl[u].append([v, w])

    def apsp(self):

        # creating adjacency matrix from adjacency list

        adj_mat = [[float('Inf')] * self.vcount for _ in
                   range(self.vcount)]
        for v in self.adjl:
            for ertex in self.adjl[v]:

                # assuming directed graph

                adj_mat[v][ertex[0]] = ertex[-1]

        for k in range(self.vcount):
            for i in range(self.vcount):
                for j in range(self.vcount):
                    adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j])
    
        # print ans
    
        for r in adj_mat:
            print(r)


g = graph(4)
g.addEdge(0, 0, 0)
g.addEdge(0, 1, 5)
g.addEdge(0, 3, 10)
g.addEdge(1, 1, 0)
g.addEdge(1, 2, 3)
g.addEdge(2, 2, 0)
g.addEdge(2, 3, 1)
g.addEdge(3, 3, 0)

g.apsp()