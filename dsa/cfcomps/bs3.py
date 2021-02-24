ssip = lambda : map(int, input().split())
n,x,y=ssip()
def possip(n,x,y,t):
    
    nc = 1
    t -= min(x,y)
    return (1 + t//x + t//y) >=n

l = 0 
r = int(1e18)

while  l+1<r:
    m = (l+r)//2
    if possip(n,x,y,m):
        r = m     
    else: l = m 
print(r)