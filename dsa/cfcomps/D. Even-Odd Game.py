for _ in range(int(input())):
    n = int(input())
    w = list(map(int,input().split()))
    e,o=[],[]
    for i in w:
        if i%2==0:
            e.append(i)
        else: o.append(i)
    e.sort()
    o.sort()
    a=b=0
    for i in range(n):
        if i%2==0:
            try:
                ev = e[-1]
                if o[-1]>ev:
                    o.pop()
                else:a+=e.pop()
            except:
                if e:
                    a+=e.pop()
                else:
                    o.pop()
        else:
            try:
                if e[-1]>o[-1]:
                    e.pop()
                else:
                    b+=o.pop()
            except :
                if o:
                    b+=o.pop()
                else:
                    e.pop()
        # print(a,b)
    if a==b:
        print("Tie")
    elif a>b:
        print("Alice")
    else:
        print("Bob")



    