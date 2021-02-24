for _ in range(int(input())):
    n = int(input())
    w = list(map(int,input().split()))
    ans = []
    ad = {i:w[i] for i in range(n)}
    for i in range(n-1,-1,-1):
        xx = i+w[i]
        if xx<n:
            ad[i]+=ad[xx]

    print(max(ad.values()))


    