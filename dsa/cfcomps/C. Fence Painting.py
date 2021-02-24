from collections import defaultdict
for _ in range(int(input())):
    n,m = map(int, input().split())
    ai = list(map(int, input().split()))
    bi = list(map(int, input().split()))
    ci = list(map(int, input().split()))

    neqd = defaultdict(int)
    eqd = defaultdict(int)
    neqi = defaultdict(list)
    eqi = defaultdict(list)
    for i in range(n):
        if ai[i]==bi[i]:
            eqd[ai[i]]+=1
            eqi[ai[i]].append(i+1)
        else:
            neqd[bi[i]]+=1
            neqi[bi[i]].append(i+1)

    cj = []
    for i in ci:
        if neqd[i]>0:
            neqd[i]-=1
            cj.append(neqi[i].pop())
        elif eqd[i]>0:
            eqd[i]-=1
            cj.append(eqi[i].pop())
        else:
            break

    if len(cj)==m:
        print("YES")
        print(*cj)
    else:
        print("NO")