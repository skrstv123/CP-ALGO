#common bin sq samesum
from collections import defaultdict as d
def lcss(s1,s2):
    assert len(s1)==len(s2)
    pr1=pr2=0
    difd=d(lambda : -1)
    ml=0
    for i in range(len(s1)):
        pr1+=int(s1[i])
        pr2+=int(s2[i])
        cdif=pr1-pr2 
        if cdif==0: ml=i+1 
        elif difd[cdif]==-1: difd[cdif]=i
        else: ml=max(ml,i-difd[cdif])
    return ml 
l='001100101'
m='1000001'
print(lcss(l,m))