#mcpath
#topDown
from sys import maxsize
class mc(dict):
    def __missing__(self,args):
        cm,r,c=args
        if r<0 or c<0: #to topleft
            return maxsize
        elif r==c==0:
            self[args]=x=cm[0][0]
            return x
        else:
            self[args]=x=cm[r][c]+ min(self[cm,r-1,c-1],self[cm,r-1,c],self[cm,r,c-1])
            return x
# dpd=mc()
# cm=((1,2,3),(4,8,2),(1,5,3))
# x=dpd[cm,2,2]
# print(x)

#botmup
def mcbu(cm,r,c,fr=0,fc=0):
    dp=dict()
    dp[0,0]=cm[0][0]
    #col
    for i in range(1,r+1):
        dp[i,0]=dp[i-1,0]+cm[i][0]
    #ro
    for j in range(1,c+1):
        dp[0,j]=dp[0,j-1]+cm[0][j]
    for i in range(1,r+1): #ro
        for j in range(1,c+1): #co
            dp[i,j]=cm[i][j] + min(dp[i-1,j-1],dp[i-1,j],dp[i,j-1])
    return dp[r,c]
# print(mcbu(((1,2,3),(4,8,2),(1,5,3)),2,2))