n,d = map(int,input().split())
li = list(map(int,input().split()))

def safex(x,l=li,d=d):
    mxprf = [0]
    for i in l:
        mxprf.append(mxprf[-1] + i - x)
    minprf = [0]
    for i in range(1, len(mxprf)):
        if mxprf[i]<mxprf[minprf[-1]]:
            minprf.append(i)
        else:
            minprf.append(minprf[-1])        
    p=q=-1
    mx= - float('inf')
    for i in range(d, len(mxprf)):
        left = mxprf[minprf[i-d]]
        if mxprf[i] >= left:
            p=minprf[i-d]+1
            q=i
            break
    # print(x, mxprf, minprf, p,q)
    return p,q 

l = 0 
r = 101
for i in range(50):
    mi = (l+r)/2
    p,q = safex(mi)
    if not p==q==-1:
        l = mi
    else:
        r = mi
print(*safex(l))

# safex(11)
