import sys
from math import ceil
print = lambda x:sys.stdout.write(str(x)+'\n')
input = lambda: sys.stdin.readline()
for _ in range(int(input())):
    n,k = map(int,input().split())
    l = list(map(int,input().split()))
    x = l[0]   
    for i in range(1,n):
        d = l[i]
        if d*100> x*k:
            x+=d*100-x*k
        x+=d
    print(x-sum(l))




