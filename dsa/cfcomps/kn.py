def ltk(x,k,s):
    c = 0 
    for l in range(1,1+s):
        # closest multiple of l
        if s*l<x:
            c+=s
            continue

        p = x//l
        if x%l==0: p-=1 
        if p>0: c+=p
    return c<k

def lb(a,x):
    l= -1
    r = len(a)
    while l+1<r:
        mi = (l+r)//2 
        if a[mi]<x:
            l = mi
        else: r=mi
    return r

def ltkl(x,a,b,k):
    ans= 0
    for i in a:
        p = x-i 
        ans+=lb(b,p)
        # print(x,p,lb(b,p))
    return ans<k

n,k= map(int,input().split())
# segs = [list(map(int,input().split())) for _ in range(n)]
a = list(map(int,input().split()))
b = list(map(int,input().split()))
a.sort()
b.sort()
# print(a)
# print(b)
l = 0
r = (max(a)*max(b))+1

while l+1<r:
    mi = (l+r)//2
    if ltkl(mi, a, b, k):
        l= mi
    else:r=mi
print(l)