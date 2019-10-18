#Euclid's algorithm
def gcd(a,b):
	if b==0:
		return a;
	else:
		return gcd(b, a%b) 
		

#modular inverse using fermats little theorem [mod mul inv of a%m is x if (a*x)%m=1]
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

