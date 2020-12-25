n,m = map(int, input().split())
import sys; sys.setrecursionlimit(1<<20)
l=[list(input()) for _ in range(n)]
from collections import defaultdict
vis=defaultdict(bool)

def pdfs(l, s):
    vis[s]=True
    x,y=s 
    #left 
    if y>0:
        if l[x][y-1]=='.' and not vis[x,y-1]: pdfs(l,(x,y-1))
    #right 
    if y+1<m:
        if l[x][y+1]=='.' and not vis[x,y+1]: pdfs(l,(x,y+1))
    #up
    if x>0:
        if l[x-1][y]=='.' and not vis[x-1,y]: pdfs(l,(x-1,y)) 
    #down 
    if x+1<n:
        if l[x+1][y]=='.' and not vis[x+1,y]: pdfs(l,(x+1,y)) 

rooms=0
for i in range(n):
    for j in range(m):
        if l[i][j]=='.' and vis[i,j]==False:
            rooms+=1 
            pdfs(l, (i,j))
print(rooms)