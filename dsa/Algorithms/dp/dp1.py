#kadane (ndp)
def kd(a):
    mf=mc=0
    for e in a:
        mc+=e 
        mf=max(mf,mc)
        if mc<0:mc=0
    return mf 
print(kd([-2,-3,4,-1,-2,1,5,-3]))