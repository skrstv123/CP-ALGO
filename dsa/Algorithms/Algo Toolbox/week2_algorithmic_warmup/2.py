def pisanoPeriod(m): 
    previous, current = 0, 1
    for i in range(m*m): 
        previous,current=current, (previous+current)%m 
        if (previous == 0 and current == 1): 
            return i + 1

def fibmodm(n,m): 
    pis= pisanoPeriod(m) 
    n = n % pis
    previous, current = 0, 1    
    for i in range(n-1): 
        previous, current = current, previous + current       
    return current%m
n,m=map(int,input().split())
print(fibmodm(n,m))
# print(pisanoPeriod(1000))