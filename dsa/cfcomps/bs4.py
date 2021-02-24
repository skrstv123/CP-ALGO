
ssip = lambda : map(int, input().split())
m,n = ssip()
ast = [list(ssip()) for _ in range(n)]
ans = []

def safe(m,ast, t):
    global ans 
    ans.clear()
    ba = 0
    for ti,y,z in ast:
        if ba>=m:
            ans.append(0)
            continue
        ca= cp= 0 
        ttt = t
        while ttt>=ti:
            if ca-cp>=z:
                cp = ca 
                ttt-=y
            if ca>=m:
                break
            ttt -= ti 
            ca+=1

        ans.append(ca)
        ba+=ca
    return ba>=m 

l = 0 
r = int(1e9)
while l+1<r:
    mi = (l+r)//2
    if safe(m,ast, mi):
        r = mi 
    else:
        l = mi 
print(r)
safe(m, ast, r)
print(*ans)