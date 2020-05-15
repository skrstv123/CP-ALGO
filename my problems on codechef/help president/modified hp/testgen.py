import sys 
from collections import defaultdict as dd 
from random import randint, choice, shuffle

def tc(n,yes=True): #the test case
    print(n)
    x= [chr(randint(65,90))  for i in range(n)]
    y= list(x) if yes else [chr(randint(65,90))  for i in range(n)]
    shuffle(y)
    for i in range(n):
        print(i, x[i], y[i])

def mktcf(N): # make test cases files
    for f in range(N):
        sys.stdout = open('tcf{}.txt'.format(f),'w')
        t=randint(1,1000)
        print(t)
        for tc_ in range(t):
            n= randint(2, 1000)
            tc(n, tc_&1)

N=3 #no of test files
# mktcf(N)

def solve():
    for tc in range(int(input())):
        n = int(input())
        ordered = dd(list)
        received = dd(list)

        for i in range(n):
            i,o,r=input().split()
            ordered[o].append(int(i))
            received[r].append(int(i))

        fails = []
        for size in ordered.keys():
            if len(ordered[size])>len(received[size]):
                fails.extend(sorted(ordered[size][len(received[size]):]))

        if len(fails)==0: print('YES') 
        else: 
            print(len(fails))
            print(*sorted(fails))

def mksols(N): # make solution files
    for f in range(N):
        sys.stdin = open('tcf{}.txt'.format(f),'r')
        sys.stdout = open('tcSol{}.txt'.format(f),'w')
        solve()

mksols(N)