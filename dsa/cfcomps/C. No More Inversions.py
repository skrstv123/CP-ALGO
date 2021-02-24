for _ in range(int(input())):
    n,k = map(int, input().split())
    l = list(range(1, k+1))
    if k==1:
        print(*l)
    else:
        if n>k:
            l[-1],l[-2] = l[-2], l[-1]
        elif n<k:
            l[n],l[n-1] = l[n-1], l[n]
        print(*l)

