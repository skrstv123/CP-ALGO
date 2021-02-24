ssi = lambda :map(int,input().split())
n,k = ssi()
pairs = [list(ssi()) for i in range(n)]
pairs.sort(reverse = 1, key=lambda x:x[0]/x[1])
def isok(x, pairs=pairs, k  =k):
    global i
    num = [0]
    den = [0]
    for i,j in pairs:
        num.append(num[-1] + i)
        den.append(den[-1] + j)
    if i==0:
        print(num, den)
    for i in range(k, len(num)):
        if (num[i] - num[i-k])/(den[i] - den[i-k])>=x:
            print(i)
            return True
            
    return False
print(pairs)

l = 0
r = 10
for i in range(100):
    mi = (l+r)/2
    if isok(mi):
        l = mi
    else: r=mi
print(l)