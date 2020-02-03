'''
given a number (int)'abc..' {{ALL DIGITS MUST BE UNIQUE!}}
find the next greater number with the same set of digits
'''
#iterate from right towards left; find first number which isnt in ascending order
#if found none: number itself is the max
#else : find smallest from its right side and swap them and sort that part to get the answer

from bisect import bisect as bs

def findNext(n):
    #print(534976,536479)
    sn = list(map(int,str(n)))[::-1]
    #print(sn)
    for i in range(len(str(sn))-1):
        
        if not sn[i]<sn[1+i]:
            nl = sn[:i+1] ; p = sn[i+1]
            #print(nl,p)
                        
            q,nl[bs(nl,p)] = nl[bs(nl,p)],p 
            nl.append(q) 
            #print(nl)
            
            nl[:-1] = sorted(nl[:-1],reverse=1) #for further optimization, here also we may use bs as the list is already sorted
            #print(nl)
                     
            gl = nl + sn[i+2:] 
            return ''.join(list(map(str,gl))[::-1])
    return -1 
    
print(findNext(66))
