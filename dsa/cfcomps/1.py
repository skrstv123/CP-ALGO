for _ in range(int(input())):
    n,m,r,c = map(int, input().split())
    ans = -float('inf')
    ans = max(ans, abs(r-1) + abs(c-1)) 
    ans = max(ans, abs(r-1) + abs(c-m)) 
    ans = max(ans, abs(r-n) + abs(c-1)) 
    ans = max(ans, abs(r-n) + abs(c-m)) 
    print(ans)