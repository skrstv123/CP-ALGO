from math import sqrt
for _ in range(int(input())):
    i = int(input())
    bo = False
    if i&1==1:
        bo = True
    while i%2==0:
        i>>=1 
    if i>1:
        bo = True
    print("YES" if bo else "NO")