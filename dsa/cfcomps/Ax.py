from math import ceil
for _ in range(int(input())):
    a,b = map(int, input().split())
    ans = 0 
    if a<b:
        print(1)
        continue

    while a>0:
        ans+=1  
        if (a%2==0 and b%2==0) or b==1 :
            b+=1 
        else:
            a//=b    
    print(ans)