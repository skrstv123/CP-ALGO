from random import randint as rn
import sys 
def tf(files = 2):
    qt = {
        1: lambda : [1, rn(1,30)],       
        2: lambda : [2, rn(1,30)],
        3: lambda : [3, rn(1,30)],
        4: lambda : [4, rn(1,10)],
        5: lambda : [5 ,rn(1,10) ,rn(1,10)],
    }
    for tf in range(files):
        sys.stdout = open(f'tf{tf}.txt', 'w') 
        tc = rn(1,1000)
        print(tc)
        for i in range(tc):
            x,q = rn(1, 10**9), rn(1, 10**3)
            print(x, q)
            for j in range(q):
                qtn = rn(1, 5)
                print(qtn)
                print(*(qt[qtn]()[1:]))

def sf(files = 2):
    def fo(x,y):
        try: return int(str(x)[-y])
        except: return 0
    def fi(x,y,z):
        ll = len(str(x))
        if y<=ll:
            x = list(str(x))
            x[-y] = str(z)
            return int(''.join(x))
        else:
            return (10**(y-1))*z + int(x)
    query = {
        1: lambda x,y : "ON" if ((x>>(y-1))&1)==1 else "OFF",       
        2: lambda x,y : x|(1<<(y-1)),
        3: lambda x,y : x&(~(1<<(y-1))),
        4: fo,
        5: fi,
    }
    for tf in range(files):
        sys.stdin = open(f'tf{tf}.txt', 'r')
        sys.stdout = open(f'sf{tf}.txt', 'w')
        for _ in range(int(input())):
            x,q = map(int, input().split())
            for _ in range(q):
                qtype = int(input())
                args = [x] + list(map(int, input().split()))
                try:
                    qq = query[qtype](*args)
                    print(qq)
                    if qtype>1: x=qq 
                except : raise ValueError(str(args))

    