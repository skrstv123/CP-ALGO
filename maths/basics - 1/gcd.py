#------------------------------Euclid's algorithm-------------------------
def gcd(a,b):
	if b==0:
		return a;
	else:
		return gcd(b, a%b) 
		

#------------------modular inverse using fermats little theorem------------------------ 
#[mod mul inv of a%m is x if (a*x)%m=1]
#pre req gcd n modex 
def modex(b,e,m):
	r=1
	while e:
		if e&1:
			r=(r*b)%m 
		b=(b*b)%m 
		e>>=1 
	return r 

def mmi(a,m):
	#am-1 ≡ 1 (mod m) 
	#a-1 ≡ a m-2 (mod m)
	if gcd(a,m)==1:
	    
		return modex(a,m-2,m)
	else:
		return -1 
#driver code 
#a,m=8,3
#print(mmi(a,m))

#-----------------------euler's totient function  ?(n) ----------------------------
# ?(n) = x where x is the num of nums in range(1,n+1) if gcd(n, num)==1 
#x = n*(1 - 1/p1).(1 - 1/p2)..............

#a modified version is implemented which avoids floating number in cal. 
def etf(n):
	res = n 
	p = 2
	while p*p <= n:
		if n%p=0:
			while n%p == 0:
			
				n//=p 
				res-=res//p
		p+=1
	if n>1:
		res-=res//p
	
	return res 
#?(x) for all x in range n 
#?(x)<=x-1 always! and ?(p)=p-1 if p is prime
def etfex(n):
	etfl=[x for x in range(n+1)] 
	for i in range(2,n+1):
		if etfl[i] == i:
			etfl[i] = i-1 
			for j in range(2*i, n+1, i):
				etfl[j]*=(1 - 1/i)
	for i in range(1,n+1):
		print('?(%d) = %d'%(i,int(etfl[i])))
		



