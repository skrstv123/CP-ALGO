for _ in range(int(input())):
    h,w,n = map(int,input().split())
    x = 1
    mp = 1
    while h%2==0 or w%2==0:
        if h%2==0:
            h//=2
            
        elif w%2==0:
            w//=2
        x+=(1*mp)
        mp *= 2   
    print("YES" if x>=n else "NO")
