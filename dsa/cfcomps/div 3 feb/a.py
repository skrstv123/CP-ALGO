ssi = lambda : map(int, input().split())
for _ in range(int(input())):
    n = int(input())
    l = list(ssi())
    i= 0
    ans=0
    while i<n-1:
        s,b = sorted(l[i:i+2])
        while 2*s<b:
            s<<=1 
            ans+=1 
        i+=1    
    print(ans)
