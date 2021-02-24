for _ in range(int(input())):
    n = int(input())
    w = list(map(int,input().split()))
    s1 = w.count(1)
    s2 = w.count(2)*2
    even = lambda x: x%2==0
    ans = "YES"
    if even(s1):
        avg = (s1+s2)>>1
        if not even(avg):
            if s1==0:
                if not even(s2//2):
                    ans = "NO"
    else:
        ans="NO"

    print(ans)