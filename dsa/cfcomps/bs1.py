w,h,n= map(int, input().split())
def enough(n,w,h,x): return (x//w)*(x//h) >= n

l = 0 
r = 1 
while not enough(n,w,h,r):
    r<<=1

while l+1<r:
    m = (l+r)//2
    if enough(n,w,h,m):
        r = m 
    else: l = m 
print(r)