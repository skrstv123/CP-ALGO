from collections import defaultdict as df
import sys; sys.setrecursionlimit(1<<20)
n=int(input())
al=df(set)
for i,x in enumerate(input().split(), start=2):
    al[i].add(int(x))
    al[int(x)].add(i)
ans = df(int)
def subs(par, src, al):
    x=0
    for c in al[src]:
        if c!=par:
            subs(src, c, al)
            x+=(1+ans[c])
    ans[src] = x


subs(0,1,al)
for i in range(1, n+1):
    print(ans[i] , end=" ")
# import pprint;pprint.pprint(al)