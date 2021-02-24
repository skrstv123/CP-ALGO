from collections import Counter as co
for _ in range(int(input())):
    x,y = map(int, input().split())
    c = list(input())
    count_of_commands = co(c)
    cx=cy=0   
    for i in c:
        if i=='R': cx+=1   
        if i=='L': cx-=1
        if i=='U': cy+=1 
        if i=='D': cy-=1

    ans = "NO"
    if cx<x:
        if count_of_commands['L']>= x-cx:
            cx = x  
    if cx > x:
        if count_of_commands['R'] >= cx-x:
            cx = x 
    if cy>y:
        if count_of_commands['U']>= cy-y:
            cy=y 
    if cy<y:
        if count_of_commands['D'] >= y-cy:
            cy = y   

    if cx==x and cy==y:
        ans= "YES"

    print(ans)
