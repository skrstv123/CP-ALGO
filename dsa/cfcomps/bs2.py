ssip = lambda : map(int, input().split())
n,k = ssip()
rope = [int(input()) for _ in range(n)]
def cancut(rope, k, x):
    s = 0 
    for r in rope:
        s+=(r//x)
    return s>=k 

l = 0 
r = max(rope) + 1 

for i in range(100):
    m = (l+r)/2
    if cancut(rope, k, m):
        l = m     
    else: r = m

print(round(l,6))