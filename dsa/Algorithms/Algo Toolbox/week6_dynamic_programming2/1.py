# import sys
# sys.stdin=open('ip.txt','r')
from collections import defaultdict as dp
#max gold
# def mgold(W,w):
#     tbl=dp(lambda:0)
#     for i in range(1,len(w)+1):
#         for j in range(1,W+1):
#             tbl[j,i]=tbl[j,i-1]
#             if w[i-1]<=j:
#                 tbl[j,i]=max(tbl[j,i],tbl[j-w[i-1],i-1]+w[i-1])
#     # print(tbl)
#     return tbl[W,len(w)]
# W,w=map(int,input().split())
# wl=list(map(int,input().split()))
# print(mgold(W,wl))

#maxex

def maxval(dgs):
    for i in range(len(dgs)):
        mind[i,i]=maxd[i,i]=str(dgs[i]) 
    for s in range(len(dgs)):
        for i in range(len(dgs)-s-1):
            j=i+s+1
            minv,maxv=minmax(i,j)
            mind[i,j]=str(minv)
            maxd[i,j]=str(maxv)
def minmax(i,j):
    minv=float('inf')
    maxv=-minv 
    for k in range(i,j):
        a=eval(maxd[i,k]+ops[k]+maxd[k+1,j])
        b=eval(maxd[i,k]+ops[k]+mind[k+1,j])
        c=eval(mind[i,k]+ops[k]+maxd[k+1,j])
        d=eval(mind[i,k]+ops[k]+mind[k+1,j])
        minv=min(minv,a,b,c,d)
        maxv=max(maxv,a,b,c,d)
    return min(minv,a,b,c,d),max(maxv,a,b,c,d)
# print("\033[95m" + "change 95 to change text colors! " + "\033[0m")
dataset = input()
digits = list(dataset[0::2])
ops = list(dataset[1::2])
maxd=dp(lambda:0)
mind=dp(lambda:0)
maxval(digits)
print(maxd[0,len(digits)-1])