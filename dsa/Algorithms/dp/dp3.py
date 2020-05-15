#lcs topdown
def lcs(s1,s2):
    m,n=len(s1),len(s2)
    lcsuff=dict()
    r=0 
    for i in range(m+1):
        for j in range(n+1):
            if i==0 or j==0:
                lcsuff[i,j]=0 
            elif s1[i-1]==s2[j-1]:
                lcsuff[i,j]=lcsuff[i-1,j-1]+1
                r=max(r,lcsuff[i,j])
            else:
                lcsuff[i,j]=0
    return r

# print(lcs('geeksForGeeks','shekhargeek'))
# lcs botup
class lcsbu(dict):
    def __missing__(self,arg):
        s1,s2,i,j=arg
        if i==0 or j==0:
            # self[i,j]=0
            return 0
        elif s1[i-1]==s2[j-1]:
            self[s1,s2,i,j]=x=self[s1,s2,i-1,j-1]+1
            x=max(x,self[s1,s2,i,j-1],self[s1,s2,i-1,j])
            return x
        else: return 0
sd=lcsbu()
print(sd['geeksForGeeks','srgeek',13,6])