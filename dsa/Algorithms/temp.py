"""
    globally  @skrstv123
    
set operations
# & intersection
# | union 
# ^ symm difference
# .add to add new elements
# .difference to find difference b/w two sets
# .pop() removes an item
# .clear
# .update

#dict : __missing__

"""
from bisect import insort # args : list, element,beg,end 
import math as mt 
import heapq # heapify(list), nlargest(n,heap), nsmallest(n, heap), heappop(heap) ,heappush(heap,e)
from functools import lru_cache #memoise: maxsize
from collections import deque,Counter #pop , popleft ; 
from itertools import combinations as c #iter, c
class slist(list): #spl sort
    def _sort(self, func=lambda n: n):
        for i in range(len(x)-1):
            if func(x[i]):
                min = x[i]
                for j in range(i+1,len(x)):
                    if func(x[j]) and x[j]<min:
                        x[i],x[j]=x[j],x[i]
def soe(n): #10^7
	p = [True for _ in range(n)]
	p[0]=p[1]=False
	for i in range(2,int(mt.sqrt(n))):
		if i:
			for j in range(i*i,n,i):
				p[j]=0 
	return p
def simple_prime(x):
    if x<2: return False
    if x==2: return True
    if x%2==0: return False
    for i in range(3,mt.ceil(mt.sqrt(x)),2):
        if x%i==0: return False 
    return True
def modex(a,b,m): 
	r= 1 
	while b:
		if b&1:
			r=(r*b)%m 
		b>>=1
		a=(a*a)%m 
	return r 
def modinv(a,m): return modex(a,m-2,m) if mt.gcd(a,m)==1 else -1


intinp = lambda : int(input()) 
def listinp(func= int): return list(map(func,input().split())) 

#-------------------code------------------------

# for _ in range(intinp()):
#     pass