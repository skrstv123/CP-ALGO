'''
ncr = C(n,r) = (n!)/((r!)*(n-r)!) ; is the general definition
------recursive definition------
 C(n, r) = C(n-1, r-1) + C(n-1, r)
 C(n, 0) = C(n, n) = 1
'''
#---------------------------recursive----------------------------
def ncr(n,r):
    if r==0 or r==n: return 1 
    return ncr(n-1,r-1) + ncr(n-1,r) 
  
#print(ncr(100,4))
 
#-------with DP: 0---------- 
from collections import defaultdict
def ncrDP0(n, r):
    C = defaultdict(lambda:0)
    for i in range(n+1): 
        for j in range(min(i, r)+1): 
            if j == 0 or j == i: 
                C[i,j] = 1
            else: 
                C[i,j] = C[i-1,j-1] + C[i-1,j] 
    return C[n,r]
#print(ncrDP0(100,9))   
 
#-------with DP: 1----------
class ncrDP1(dict):
    def __missing__(self, k):
        n,r = k
        if r==0 or r==n: 
            self[k] = 1 
            return 1
        K = self[n-1,r-1] + self[n-1,r]
        self[k]= K
        return K

#ncrDict = ncrDP1()      
#print(ncrDict[100,9])