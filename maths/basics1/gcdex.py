def gcdExtended(a, b, x=1, y=1): 

    if a == 0 :  
        x = 0
        y = 1

        return b 

    x1 = 1
    y1 = 1

    gcd = gcdExtended(b%a, a, x1, y1)

    x = y1 - (b/a) * x1 
    y = x1 

    #print(x,y) 

    return gcd,x,y

print(gcdExtended(3,12)) 
#print(x,y)
