from collections import deque,defaultdict
from heapq import *
class Graph:
    """
    following freecodecamp
    """
    def __init__(self,n=None):
        self.node_count=n
        self.adj_list=defaultdict(list)
        self.dict_of_dict = defaultdict(lambda:defaultdict(lambda:float('inf')))
        # for faster execution,create either but not both of adjacency list representations
        self.adj_matrix=None
        self.edge_count=0  

    def add_edge(self,u,v,w,directed=True):
        if not directed:
            self.adj_list[u].append([v,w])
            self.adj_list[v].append([u,w])  
            self.dict_of_dict[u][v]=self.dict_of_dict[v][u]=w #avoid if speed is a concern  
        else:
            self.adj_list[u].append([v,w])
            self.dict_of_dict[u][v]=w #avoid if speed is a concern 
        self.edge_count+=1

    def list_to_mat(self):
        n=self.node_count
        mat=[[float('inf')]*(1+n) for _ in range(n+1)]
        for u in self.adj_list:
            for v in self.adj_list[u]:
                mat[u][v[0]]=v[1] 
        self.adj_matrix=mat 
        return mat 
    
    def dfs(self,at,visited=None,result_list=[]):
        if visited is None:
            visited = defaultdict(lambda : False) 
        if visited[at]: return 
        visited[at]=True 
        result_list.append(at)
        for node,weight in self.adj_list[at]:
            self.dfs(node,visited,result_list)
        return result_list 

    def count_components(self):
        assert len(self.adj_list.keys())!=0

        def dfs_modified(at,components,count_of_components,visited,graph=self.adj_list):
            visited[at]=True 
            components[at]=count_of_components 
            for v,w in graph[at]:
                if not visited[v]:
                    dfs_modified(v,components,count_of_components,visited,graph)

        self.count_of_components = 0 
        visited = defaultdict(lambda:False) 
        components=defaultdict(lambda : None)
        for u in self.adj_list:
            if not visited[u]:
                self.count_of_components+=1 
                dfs_modified(u,components,self.count_of_components,visited,graph=self.adj_list) 
        
        return self.count_of_components

    def bfs(self, start, end):
        def _bfs(start, graph=self.adj_list):
            q=deque([])
            q.append(start)
            visited=defaultdict(lambda : False)
            visited[start]=True
            prev=defaultdict(lambda : None)

            while q:
                node=q.popleft()
                neighbours = graph[node]

                for next_v,w in neighbours:
                    if not visited[next_v]:
                        q.append(next_v)
                        visited[next_v]=True
                        prev[next_v]=node
            return prev 

        def make_path(start,end,prev):
            at=end
            path=[]
            while at!=None:
                path.append(at)
                at=prev[at] 

            if path[-1]==start: return path[::-1]
            return []

        prev=_bfs(start)
        return make_path(start,end,prev)

    def dijkstra(self, start, end, fetch_path = False):
        pq=[(0,start)]
        visited=defaultdict(lambda:False)
        distances=defaultdict(lambda:float('inf'))
        distances[start]=0 
        prev = defaultdict(lambda:None) 

        while pq:
            cost, u = heappop(pq)
            if not visited[u]:
                visited[u]=True
                if u==end: 
                    if not fetch_path:
                        return distances
                    else: break

            for v,c in self.adj_list[u]:
                if visited[v]: continue
                weight_here = c + cost 
                last_weight = distances[v]
                if weight_here<last_weight:
                    prev[v]=u 
                    distances[v]=weight_here
                    heappush(pq,(weight_here,v))

        if fetch_path and distances[end]!=float('inf'):
            curr=end 
            path = []
            while curr!=None:
                path.append(curr)
                curr = prev[curr]
            return distances,path[::-1]

        return distances
        # return float('inf')

    def bellman_ford(self, start):
        distances=defaultdict(lambda:float('inf'))
        distances[start]=0
        prev=defaultdict(lambda:None)
        edges=[]
        for u in self.adj_list.keys():
            for v,w in self.adj_list[u]:
                edges.append([u,v,w])

        for i in range(self.node_count-1):
            for u,v,w in edges:
                if distances[u]!=float('inf') and distances[u]+w<distances[v]:
                    distances[v]=distances[u]+w
                    prev[v]=u

        for u,v,w in edges:
            if distances[u]!=float('inf') and distances[u]+w<distances[v]:
                # distances[v]=-float('inf')
                # raise ValueError("Negative cycle found!")
                print("There's a negative cycle!"); break

        return distances

    def floyd_warshall(self,check_negCycle = False,make_path = False):
        self.list_to_mat()
        dp = [list(r) for r in self.adj_matrix]
        res = defaultdict(lambda:None)
        if make_path:
            path_table = defaultdict(lambda:None)
            for i in range(1,self.node_count+1):
                for j in range(1,self.node_count+1):
                    if self.adj_matrix[i][j]!=float('inf'):
                        path_table[i][j]=j 
        
        res['weight_table'] = dp 
        if make_path: res['path_table'] = path_table
 
        for k in range(1,self.node_count+1):
            for i in range(1,self.node_count+1):
                for j in range(1,self.node_count+1):
                    if dp[i][k] + dp[k][j]<dp[i][j]:
                        dp[i][j] = dp[i][k] + dp[k][j]
                        if make_path:
                            path_table[i][j] = path_table[i][k] 

        if check_negCycle:
            nc=False
            for k in range(1,self.node_count+1):
                for i in range(1,self.node_count+1):
                    for j in range(1,self.node_count+1):
                        if dp[i][k] + dp[k][j]<dp[i][j]:
                            # dp[i][j]=-float('inf')
                            # path_table[i][j]=-1 if 
                            # uncomment above two lines and comment lines below to return tables which support path construction for the case of negative cycles
                            nc=True
                            break
            res['negative_cycles'] = nc 
        
        return res

    def make_path_for_floydWarshal(self, path_table, weight_table, start, end):
        path = [] 
        if weight_table[start][end]==float('inf'): return []
        at=start
        while at!=end:
            # if at is -1 : return None
            path.append(at)
            at = path_table[at][end]
         
        # if path_table[at][end]==-1: return None
        return path

        

g = Graph(5)  
g.add_edge(0, 1, -1)  
g.add_edge(0, 2, 4)  
g.add_edge(1, 2, 3)  
g.add_edge(1, 3, 2)  
g.add_edge(1, 4, 2)  
g.add_edge(3, 2, 5)  
g.add_edge(3, 1, 1)  
g.add_edge(4, 3, -3)
# print(gp.adj_list)
# print(gp.dijkstra(1,5,fetch_path=False)[5])
print(g.floyd_warshall()['weight_table'])