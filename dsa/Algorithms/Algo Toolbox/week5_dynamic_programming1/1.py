# import sys
# sys.stdin=open('ip.txt','r')
from collections import defaultdict as d
# money change
# def mc(n):
#     ma=[float('inf')]*(n+1)
#     ma[0]=0
#     for i in range(1,n+1):
#         for c in 1,3,4:
#             if c<=i:ma[i]=min(1+ma[i-c] ,ma[i])
#     return ma[n]
# n=int(input())
# print(mc(n))

#primitive calc
# def minimise(n):
#     c=[0]*(n+1)
#     for i in range(2,n+1):
#         s1=c[i-1]+1
#         m2=m3=float('inf')
#         if i&1==0: m2=c[i>>1]+1 
#         if i%3==0: m3=c[i//3]+1 
#         c[i]=min(s1,m2,m3) 
#     return c
# def minlist(n,c):
#     ints=[]
#     while n:
#         ints.append(n)
#         if n&1==1 and n%3!=0: n-=1
#         elif n&1==0 and n%3==0:
#             if c[n-1]<c[n//3]:
#                 n-=1 
#             else: n//=3 
#         elif n&1==0:
#             if c[n-1]<c[n>>1]:
#                 n-=1 
#             else: n>>=1 
#         elif n%3==0:
#             if c[n-1]<c[n//3]:
#                 n-=1 
#             else: n//=3 
#     return ints[::-1] 

# def findseq(n):
#     if n==1: return [1]
#     c=minimise(n)
#     return minlist(n,c)
# n=int(input())
# l=findseq(n)
# print(len(l)-1)
# print(*l)

#edit distance
# def eddis(s1,s2):
#     m,n=len(s1),len(s2)
#     acts=[[0]*(n+1) for i in range(m+1)] #n+1 cols & m+1 rows
#     for i in range(m+1):
#         for j in range(n+1):
#             if i==0 or j==0: acts[i][j]=j|i  #as we need to insert/copy all chars from non-empty to empty str
#             elif s1[i-1]==s2[j-1]:acts[i][j] = acts[i-1][j-1] #if matched, leave that posn from both strrings
#             else:acts[i][j]=1+min(acts[i][j-1],acts[i-1][j],acts[i-1][j-1])
#             # acts[i][j-1] insering in 1st so current char in firstt which mismatched is still there but for second string a match is made at that position so we move 2nd pointer only
#             # acts[i-1][j] deleting char from first creates a void for left char which should be compared next
#             # acts[i-1][j-1] replacing either creates match at current  position for both, so now compare left from both
            
#     return acts[m][n] 

# print(eddis(input(),input()))

#lcs of 2
# def lcs2(s1,s2):
#     a,b=len(s1),len(s2)
#     tbl=[[0]*(b+1) for _ in range(a+1)]
#     for r in range(a+1):
#         for c in range(b+1):
#             if r==0 or c==0:tbl[r][c]=0 
#             elif s1[r-1]==s2[c-1]:tbl[r][c]=tbl[r-1][c-1]+1 
#             else:tbl[r][c]=max(tbl[r-1][c],tbl[r][c-1])
#     return  tbl[a][b]
# a=input()
# aa=input().split()
# b=input()
# bb=input().split()
# print(lcs2(aa,bb))

#lcs of 3
# def lcs3(s1,s2,s3):
#     tbl=d(lambda:0)
#     a,b,c=len(s1),len(s2),len(s3)
#     for i in range(a+1):
#         for j in range(b+1):
#             for k in range(c+1):
#                 if i==0 or j==0 or k==0:tbl[i,j,k]=0 
#                 elif s1[i-1]==s2[j-1]==s3[k-1]:tbl[i,j,k]=tbl[i-1,j-1,k-1]+1 
#                 else:tbl[i,j,k]=max(tbl[i-1,j,k],tbl[i,j-1,k],tbl[i,j,k-1])
#     return tbl[a,b,c]
# # print(lcs3(input(),input(),input()))
# b=input()
# bb=input().split()
# b=input()
# cc=input().split()
# b=input()
# dd=input().split()
# print(lcs3(bb,cc,dd))