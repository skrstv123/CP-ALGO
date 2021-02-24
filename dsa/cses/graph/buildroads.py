from collections import defaultdict as df 
import sys; sys.setrecursionlimit(1<<20)
def dfs(s):
    vis[s]=True
    for i in gp[s]:
        if not vis[i]: dfs(i)

n,m=map(int, input().split())
gp=df(set)
vis=df(bool)
for i in range(m):
    a,b=map(int, input().split())
    gp[a].add(b)
    gp[b].add(a)
    vis[a]=vis[b]=False

l=[]
for i in range(1,n+1):
    if not vis[i]:
        l.append(i)
        dfs(i)

print(len(l)-1)
for i in range(len(l)-1):
    print(l[i],l[i+1])
