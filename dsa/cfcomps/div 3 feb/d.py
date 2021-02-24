import sys
sys.setrecursionlimit(10**5)

def marker(cl, i,j):
    global nodes 
    global level
    if i>j or j<i:
        return 0
    if i==j:
        if level[i]==-1: level[i] = cl+1 
        return 0
    else:
        maxel = maxin = -1
        for idx in range(i, j+1):
            if nodes[idx]>maxel:
                maxel = nodes[idx]
                maxin = idx
        if level[maxin]==-1: level[maxin] = cl+1 
        cl+=1 
        marker(cl, i, maxin-1) 
        marker(cl, maxin+1, j)

ssi = lambda : list(map(int, input().split()))
for _ in range(int(input())):
    n = int(input())

    nodes = ssi()

    level = [-1]*n

    marker(-1, 0, n-1)
    print(*level)

