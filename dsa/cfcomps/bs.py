n = int(input())
li = list(map(int, input().split())) 
li.sort()

def lb(l,x):
    le = -1
    ri = len(l)
    while le+1<ri:
        m = (le+ri)>>1 
        if l[m]<x:
            le = m   
        else:
            ri = m  
    return ri

def ub(l,x):
    le = -1
    ri = len(l)
    while le+1<ri:
        m = (le+ri)>>1 
        if l[m]<=x:
            le = m   
        else:
            ri = m  
    return le

for q in range(int(input())):
    l,r = map(int, input().split())
    le = lb(li,l)
    ri = ub(li,r)
    # print(le, ri)
    print(ri-le+1, end=' ')