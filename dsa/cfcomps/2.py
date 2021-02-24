from collections import Counter as co, deque as dq
for _ in range(int(input())):
    n,k =  map(int, input().split())
    c  = list(map(int, input().split()))
    ans = 0
    mc = max([x for x in co(c).items()], key=lambda x: x[1]) 
    i = 0 
    while i<n:
        if c[i]!=mc[0]:
            ans+=1 
            i+=k 
        elif i+k>=n:
            for _ in range(i,n):
                if c[i]!=mc[0]:
                    ans+=1 
                    break 
            break
        else:
            i+=1
    print(ans)