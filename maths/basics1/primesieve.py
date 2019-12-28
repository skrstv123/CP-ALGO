#-----------------sieve of eratosthenes--------------------
# upper limit : 10**7
from math import sqrt,ceil
def soe(n):
	p = [True for _ in range(n)]
	p[0]=p[1]=False
	for i in range(2,int(sqrt(n))):
		if i:
			for j in range(i*i,n,i):
				p[j]=0 
	return p

# print(soe(100)[:20])

#----------------n//2 sieve-----------------------