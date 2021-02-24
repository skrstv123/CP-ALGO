for _ in range(int(input())):
    n,d = map(int, input().split())
    l = list(map(int, input().split()))
    l.sort()
    boo = False
    if n<3:
        for i in l:
            if i>d:
                boo = True
                break
        
    else:
        i,j = l[:2]
        if max(l)>d and i+j>d:
            boo = True

    print("NO" if boo else "YES")
    
    