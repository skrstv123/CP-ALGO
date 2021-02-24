for _ in range(int(input())):
    n =int(input())
    l = list(map(int,input().split()))
    ans= 1
    max_ans = 1
    for i in range(1, n):
        if l[i]==l[i-1]:
            ans+=1 
            max_ans = max(ans, max_ans)
        else:
            ans = 1
    print(max_ans)