# adding x to each element in [l:r]
# d[i] = a[i]-a[i-1] ; i in [1:n]
# d[l]+=x;d[r+1]-=x 
# a[i]=a[i-1] + d[i] ; i in [1:n]

def inDifAr(a):
    d = a[0:1]+[0]*(len(a)) #one extra space for d[r+1]-=x
    for i in range(1,len(a)):
        d[i]  = a[i] - a[i-1] 
    return d   
def update(l,r,x,d):
    d[l]+=x
    d[r+1]-=x
def updatedArr(a,d):
    a[0] = d[0]
    for i in range(1,len(a)):
        a[i] = d[i] + a[i-1]

letA = list(range(1,11))
D = inDifAr(letA)
for _ in range(int(input())):
    l,r,x = map(int,input().split())
    update(l,r,x,D)
updatedArr(letA,D)
print(letA)