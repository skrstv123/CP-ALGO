#primality of very large numbers (order 10^10)

# checks if a number n is prime 
# k is a input parameter which measures accuracy of the test 
# generally k = 4   

# compute d & r such that d*(2^r) = n-1 

# ------miller test--------
# randomly choose 'a' in range(2,n-1) 
# compute x = (a**d)%n 
def modex(a,b,m):
    r=1
    while b:
        if b&1:
            r=(r*a)%m 
        a=(a*a)%m 
        b>>=1
    return r
# if x==n-1:
#     return true 

# else:
#     keep squaring x while d!=n-1
#           d//=2
#          (x^2)%n == (1<return False> else if n-1<return True>) 
from random import randint 
def miller(d,n):
 
    a  = 2+randint(1,n-4)

    x=  modex(a,d,n)
    if x in [1,n-1]: return True

    while d!=n-1:
        x=modex(x,2,n)
        d<<=1 
        if x==1: return False
        if x==n-1: return True

    return False
# ------prime checker func--------

def checkprime(n, k =4 ):
    if n<=1 or n==4:
        return False
    if n<=3: return True

    #finding d 
    d=n-1
    while d%2==0:
        d//=2 
    #now d*(2^r)= n-1

    #perform miller test k times
    for _ in range(k):       
        if not miller(d,n):
            return False 
    return True
        
if __name__ == "__main__":
    for i in range(20):
        print(i,checkprime(i))
