"""
to print the nth digit consisting of digits {0,1,2,3,4,5,6}

Ans :(for general case) n in base len(set of given digits) 
"""
def toBase(n,b):
    if n==0: return 0 
    l=[]
    while n:
        l.append(str(n%b))
        n//=b 
    return ''.join(l[::-1])

N = int(input())
print(toBase(N,6))