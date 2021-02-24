ssi = lambda : list(map(int, input().split()))
for _ in range(int(input())):
    n = int(input())
    l = ssi()
    li = [(l[i], i) for i in range(n)]
    li.sort(key = lambda x: x[0], reverse=True)
    prfs = []
    for e, _ in li[::-1]:
        if len(prfs)==0:
            prfs.append(e)
            continue
        prfs.append(prfs[-1] + e)
    prfs.reverse()
    # print(prfs)

    ans = [False]*n  
    for _ in range(len(li)):
        e, i = li[_]
        if _==0:
            flag = False
            ans[i] = True
        elif _<n-1 and (prfs[_+1]+e)>=li[_-1][0] and ans[li[_-1][1]]:
            ans[i] = True
        elif e==li[_-1][0] and ans[li[_-1][1]]:
            ans[i] = True
    print(ans.count(True))
    for i in range(n): 
        if ans[i]: print(i+1, end = " ")
    print()



