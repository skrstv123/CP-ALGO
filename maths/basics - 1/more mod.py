#mod of number taken as string (very large integer)
def modbig(string, mod):
	res=0
	for i in range(len(string)):
		res+=(res*10 + int(string[i]))%mod 
	return res 
	
#driver code 
#print(modbig("5486761497534879855487453423167865454573456464",75)) 

#finding (bignum^someint)%mod 
#first calc bignum%mod 
#bignum = "5486761497534879855487453423167865454573456464" ; mod = 5

def bigmodex(bignum, someint, mod ):
	ans = b = modbig(bignum, mod)
	for _ in range(1, someint - 1):
		ans = (ans*b)%mod 
		
	return ans 

#----------------------------square root under mod p----------------------------------

# 1.  p%4==3 then sqrt under mod is +-(n^((p+1)//4))%mod
# requires modex 
def binaryModularExponentiation(x,n,M):
	"""
	Time complexity: O(log N)
	Memory complexity: O(1)
	"""
    result=1
    while(n>0):
    
        if(n&1):
            result=(result * x)%M
        x=(x*x)%M
        n>>=1
    return result  

def sqrtmod1(num, p):
	
	if p%4==3:
		num%=p 
		x=binaryModularExponentiation(num, (p+1)//4, p)
		
		if (x*x)%p==num:
			return x 
		x=p-x 
		if (x*x)%p==num:
			return x
	else :
		return 'root doesnt exist' 
		
#2 -----------------------shanks tonelli algo-----------------------------

	
	
	
	
	
	
	
	
	
	