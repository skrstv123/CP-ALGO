n,k=map(int, input().split())
l=list(map(int, input().split()))
ans=0
ll,rl=max(l), int(1e18)
while ll<rl:
    mid=(ll+rl)//2
    s=sc=0
    sc+=1
    for i in l:
        if s+i>mid:
            s=i
            sc+=1
        else: s+=i
    if k<sc: ll=mid+1
    else: rl=mid
print(ll)