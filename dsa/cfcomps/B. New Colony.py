for _ in range(int(input())):
    n,k = map(int, input().split())
    h = list(map(int, input().split()))
    ans = -1

    if n==1 or h==sorted(h, reverse=1):
        print(-1)
        continue

    flag = True
    while k>0 and flag:
        # k -= 1 
        flag = False
        for i in range(n-1):
            if h[i]<h[i+1]:
                flag = True
                h[i] += 1
                ans = i+1
                break
        if not flag:
            ans = -1
        k -= 1 
    print(ans)
