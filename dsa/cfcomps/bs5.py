ssip = lambda : map(int, input().split())
c = float(input())
from math import sqrt
def chk(c,x): return x*x  +  sqrt(x) - c
l = 0
r = int(1e9)
for i in range(100):
    m = (l+r)/2 
    if chk(c,m)>0:
        r = m 
    else:
        l = m 
print(l)