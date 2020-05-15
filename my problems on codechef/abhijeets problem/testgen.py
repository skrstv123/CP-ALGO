import sys 
from collections import defaultdict , Counter 
from random import randint, choice, shuffle

def tc(n):
    print(n)
    x= [randint(1,1000)  for i in range(n)]
    print(*x)

def mktcf(N):
    for f in range(N):
        sys.stdout = open('tcf{}.txt'.format(f),'w')
        t=randint(1,1000)
        print(t)
        for tc_ in range(t):
            n= randint(1, 1000)
            tc(n)
N=3
mktcf(N)

def solve():
    for tc in range(int(input())):
        n = int(input())
        l = [int(x) for x in input().split()]
        print(n-max(Counter(l).values()))
        
def mksols(N):
    for f in range(N):
        sys.stdin = open('tcf{}.txt'.format(f),'r')
        sys.stdout = open('tcSol{}.txt'.format(f),'w')
        solve()

mksols(N)