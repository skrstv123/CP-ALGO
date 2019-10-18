#modular arithmetic
"""
When one number is divided by another, the modulo operation finds the remainder. It is denoted by the % symbol.
properties;
	1> (a+b)%c  =  (a%c + b%c)%c 
	2> (a*b)%c = ((a%c)*(b%c))%c
	3> (a-b)%c = ((a%c) - (b%c) + c)%c
	4> (a/b)%m
		=> modular division
		Given three positive numbers a, b and m. Compute a/b under modulo m. 
		The task is basically to find a number c such that (b * c) % m = a % m.
	
"""
#modular exponentiation
# x^n
#1 recursive
def binaryRecExponentiation( x, n):
    if(n==0):
		return 1
    elif(n%2 == 0):        #n is even
        return binaryExponentiation(x*x,n/2)
    else:                             #n is odd
        return x*binaryExponentiation(x*x,(n-1)/2)

#2 iterative
def binaryIterExponentiation(x,n):
    result=1
    while(n>0):
    
        if(n % 2 ==1):
            result=result * x
        x=x*x
        n=n/2
    return result  
	
#3 modular exponentiation recursive
def modularExponentiation(x,n,M):
	"""
	Time complexity: O(log N)
	Memory complexity: O(log N) because a function call consumes memory and log N recursive function calls are made

	"""
    if(n==0)
        return 1
    elif(n%2 == 0):        #n is even
        return modularExponentiation((x*x)%M,n/2,M)
    else:                             #n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M

#4 modularExponentiation iterative
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
	
#modular division
from math import gcd 
def modInverse(b,m):   
    if (gcd(b,m)==1):   
        return -1
    else:    
        return binaryModularExponentiation(b, m - 2, m) 
def modDiv(a,b,m):
	x= modInverse(b,m)
	if x==-1:
		return 'division not defined'
	else :
		return (x*a)%m
		
#	driver code
#	(8/3)%5
print(modDiv(8,3,5))

  
