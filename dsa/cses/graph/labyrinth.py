from collections import deque as dq
n,m = map(int, input().split())
l=[input() for _ in range(n)]

vis = [[False]*m for _ in range(n)]
path = [[False]*m for _ in range(n)]
moves = {(0,-1):'L', (0,1):'R', (-1,0):'U', (1,0):'D'}

si=sj=ei=ej=0

for i in range(n):
    for j in range(m):
        vis[i][j]= l[i][j]=='#'
        if l[i][j]=='A':
            si=i 
            sj=j 
        elif l[i][j]=='B':
            ei=i 
            ej=j 

def bfs():
    q=dq([])
    q.append((si,sj))
    while q:
        x,y=q.popleft()
        for dx,dy in moves.keys():
            nx,ny=x+dx,y+dy 
            if nx in {-1,n} or ny in {-1,m}:
                continue
            if not vis[nx][ny]:
                q.append((nx,ny))
                vis[nx][ny]=True
                path[nx][ny]=(dx,dy)

bfs()

ans = [] 
if vis[ei][ej]:
    print('YES')
    while ei!=si or ej!=sj:
        ans.append(path[ei][ej])
        ei-=ans[-1][0]
        ej-=ans[-1][1]
    print(len(ans))
    for i in ans[::-1]:
        print(moves[i], end='')
else:
    print('NO')
#---------------------------------------------------------------------
#import time
#import bisect
#import math
import sys
#import random as r
from collections import deque
#from collections import defaultdict 
#from heapq import heapify, heappush, heappop 
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def inp_int(): return int(sys.stdin.readline().strip())
def inp_str(): return(sys.stdin.readline().strip())
def out(output): sys.stdout.write(str(output))
def get_strs(): return  sys.stdin.readline().strip().split()
sys.setrecursionlimit(10**6)
 
 
 
n, m = get_ints()
M = [list(inp_str()) for _ in range(n)]
D = ((1, 0, 'D'), (0, 1, 'R'), (-1, 0, 'U'), (0, -1, 'L'))
Q = deque([(X, Y) for X in range(n) for Y in range(m) if M[X][Y] == 'A'])
while Q:
	x, y = Q.popleft()
	for a, b, c in D:
		A = x + a
		B = y + b
		if 0 <= A < n and 0 <= B < m:
			R = M[A][B]
			if R == '.':
				M[A][B] = (x, y, c)
				Q.append((A, B))
			elif R == 'B':
				print('YES')
				p = [c]
				while M[x][y] != 'A':
					x, y, c = M[x][y]
					p.append(c)
				print(len(p))
				print(''.join(p[::-1]))
				raise SystemExit
print('NO')