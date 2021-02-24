
from math import gcd
for _ in range(int(input())):
    a  = input()
    b  = input()

    if len(b)>len(a): a,b = b,a
    if set(a)!=set(b):
        print(-1)
    else:
        boo = False
        x = len(a)
        y = len(b)
        xy = (x*y)//gcd(x,y)
        if a*(xy//x) == b*(xy//y):
            boo = True
        print(a*(xy//x) if boo else -1)
             


        

    
    