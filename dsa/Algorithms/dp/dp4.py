#lps
class lps(dict):
    #this lps isnt contigous, its any string that is palindrome 
    #only the order in which its chars appear remains same
    def __missing__(self,args):
        s1,m,n=args
        if m==n:
            self[s1,m,n]=x=1 
            return 1
        elif s1[m]!=s1[n]:
            self[s1,m,n]=x=max(self[s1,m+1,n],self[s1,m,n-1])
            return x 
        elif n-m==1 and s1[n]==s1[m]:
            self[s1,m,n]=x=2 
            return x
        else: #s1[m]==s1[n]
            self[s1,m,n]=x=self[s1,m+1,n-1]+2 
            return x 
mlp = lps()
print(mlp['madm',0,3])
