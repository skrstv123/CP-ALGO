import sys
sys.stdin=open('ip.txt','r')

# binary search
# def bs(e,a,s,l):
#     m=(s+l)>>1
#     if a[m]==e: return m 
#     if s>=l: return -1
#     if a[m]<e: return bs(e,a,m+1,l)
#     if a[m]>e: return bs(e,a,s,m)
# a=list(map(int,input().split()))[1:]
# for e in list(map(int,input().split()))[1:]:
#     print(bs(e,a,0,len(a)-1),end=' ')

#majority el
# nn=int(input())
# l=list(map(int,input().split()))
# l.sort()
# s=1;fl=False
# for i in range(nn-1):
#     if l[i]==l[i+1]:
#         s+=1 
#         if s>nn>>1: 
#             fl=True; break
#     else: s=1 
# print(1 if fl else 0)

#3way qsort
# def qsort(arr):
#     if len(arr) <= 1: return arr
#     pivot = arr[0]
#     s= [x for x in arr if x < pivot]
#     e= [x for x in arr if x == pivot]
#     g= [x for x in arr if x > pivot]
#     return qsort(s)+e+qsort(g)
# n=int(input())
# l=list(map(int,input().split()))
# print(*qsort(l))

#---------------closest points--------------
class point:
    def __init__(self,x,y):
        self.x=x; self.y=y  
    def dist(self,p2):
        return ((self.x-p2.x)**2 + (self.y-p2.y)**2)**.5 
    def __repr__(self):
        return '({} , {})'.format(self.x,self.y)

def bf(pts):
    n=len(pts)
    mn=float('inf')
    for i in range(n):
        for j in range(i+1,n):
            if pts[i].dist(pts[j])<mn:
                mn=pts[i].dist(pts[j])
    return mn 

def forStrip(pts,mn):
    n=len(pts)
    # pts=sorted(pts,key=lambda x: x.y) 
    for i in range(n):
        j=i+1 
        while j<n and pts[j].y-pts[i].y<mn :
            if pts[i].dist(pts[j])<mn:
                mn=pts[i].dist(pts[j]) 
            j+=1
    return mn

def recClp(pts,py):
    n=len(pts)
    if n<=3: return bf(pts)

    mid=n>>1
    mp=pts[mid]

    dl=recClp(pts[:mid],py)
    dr=recClp(pts[mid:],py)

    d=min(dl,dr)
    strip=[]
    for i in range(n):
        if abs(py[i].x-mp.x)<d: strip.append(py[i])
    
    return forStrip(strip,d)

# a=[2,12,40,5,12,3]
# b=[3,30,50,1,10,4]

pts=[]
n=int(input())
for _ in range(n):
    x,y=map(int,input().split())
    pts.append(point(x,y))
# print(pts)
# for x,y in [(4 , 4), (-2 , -2), (-3 , -4), (-1 , 3), (2 , 3), (-4 , 0), (1 , 1), (-1 , -1), (3 , -1), (-4,2), (-2,4)]:
#     pts.append(point(x,y))
pts.sort(key=lambda a: a.x)
py=sorted(pts,key=lambda a: a.y)
zz=recClp(pts,py)
print("{0:.9f}".format(zz))
#---------------------------mindist----------------------
#-------------------points under segments--------------
# from collections import defaultdict as d
# def fcs(s,e,p):
# 	l,po,r=1,2,3
# 	co=[0]*len(p)
# 	pmap=d(set)
# 	pair=[]
# 	for i in s:
# 		pair.append((i,l))
# 	for i in e:
# 		pair.append((i,r))
# 	for i in range(len(co)):
# 		ptt=p[i]
# 		pair.append((ptt,po))
# 		pmap[ptt].add(i)
#         # considering the points list contains duplicates
# 	pair.sort()
# 	cov=0
# 	for p in pair:
# 		if p[1]==l:
# 			cov+=1
# 		if p[1]==r:
# 			cov-=1
# 		if p[1]==po:
# 			ix=pmap[p[0]]
# 			for i in ix:
# 				co[i]=cov
# 	return co
# sc,pc=map(int,input().split())
# s,e=[],[]
# for i in range(sc):
#     a,b=map(int,input().split())
#     s.append(a)
#     e.append(b)
# po=list(map(int,input().split()))
# print(*fcs(s,e,po))
#-----------------------pus-------------------------
#---------------inversions----------------

# by modifying merge sort
# def merge(a,b):
# 	mgd=[];ic=0
# 	while a and b:
# 		if a[0]<=b[0]:
# 			mgd.append(a.pop(0))
# 		else:
# 			mgd.append(b.pop(0))
# 			ic+=len(a) 
# 	mgd += a or b 
# 	return mgd,ic 
# def msort(l):
# 	if len(l)==1: return l,0 
# 	mid=len(l)>>1
# 	sm,sic=msort(l[:mid])
# 	# print(sm,sic)
# 	gt,gic=msort(l[mid:])

# 	final,fic=merge(sm,gt)
# 	return final,fic+sic+gic 
# n=int(input())
# l=list(map(int,input().split()))
# print(msort(l)[1])