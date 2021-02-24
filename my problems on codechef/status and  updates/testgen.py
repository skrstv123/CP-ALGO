from random import randint as rn
import sys 
def tf(files = 2):
    qt = {
        1: lambda : [1, rn(1,30)],       
        2: lambda : [2, rn(1,30)],
        3: lambda : [3, rn(1,30)],
        4: lambda : [4 ,rn(1,30) ,rn(1,30)],
    }
    for tf in range(files):
        sys.stdout = open(f'tf{tf}.txt', 'w') 
        tc = rn(1,1000)
        print(tc)
        for i in range(tc):
            x,q = rn(1, 10**9), rn(1, 10**3)
            print(x, q)
            for j in range(q):
                qtn = rn(1, 4)
                print(qtn)
                print(*(qt[qtn]()[1:]))

def sf(files = 2):
    def fo(x,y,z):
        b1 = (x>>(y-1))&1
        b2 = (x>>(z-1))&1 
        x = query[2 if b1 else 3](x, z)
        x = query[2 if b2 else 3](x, y)
        return x
    query = {
        1: lambda x,y : "ON" if ((x>>(y-1))&1)==1 else "OFF",       
        2: lambda x,y : x|(1<<(y-1)), #on
        3: lambda x,y : x&(~(1<<(y-1))), #off
        4: fo,
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
                    if qtype==1:print(qq)
                    if qtype>1: x=qq 
                except : raise ValueError(str(args))

    