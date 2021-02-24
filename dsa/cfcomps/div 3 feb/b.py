ssi = lambda : list(map(int, input().split()))
from collections import defaultdict
for _ in range(int(input())):
    n = int(input())
    l = ssi()
    rms = defaultdict(int)
    for i in l: rms[i%3]+=1
    mi = n//3
    ans = 0 
    while rms[0]<mi:
        if rms[2]>mi:
            rms[2]-=1 
            rms[0]+=1 
            ans+=1 
        elif rms[1]>mi:
            rms[1]-=1 
            rms[0]+=1
            ans+=2 
    
    while rms[1]<mi:
        if rms[0]>mi:
            rms[0]-=1
            rms[1]+=1 
            ans+=1 
        elif rms[2]>mi:
            rms[2]-=1 
            rms[1]+=1 
            ans+=2 

    while rms[2]<mi:
        if rms[1]>mi:
            rms[1]-=1 
            rms[2]+=1
            ans+=1 
        elif rms[0]>mi:
            rms[0]-=1
            rms[2]+=1
            ans+=2 

    print(ans)
    