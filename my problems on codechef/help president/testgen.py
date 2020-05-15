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

def mktcf(N): # make test cases
    for f in range(N):
        sys.stdout = open('tcf{}.txt'.format(f),'w')
        t=randint(1,1000)
        print(t)
        for tc_ in range(t):
            n= randint(2, 1000)
            tc(n, tc_&1)

N=3 #no of test files
mktcf(N)

def solve():
    for tc in range(int(input())):
        n = int(input())
        ordered = dd(lambda : 0)
        received = dd(lambda : 0)

        for i in range(n):
            i,o,r=input().split()
            ordered[o]+=1
            received[r]+=1

        fails = 0 
        for size in ordered.keys():
            fails += max(0, ordered[size] - received[size])
        print('YES' if fails==0 else fails)

def mksols(N):
    for f in range(N):
        sys.stdin = open('tcf{}.txt'.format(f),'r')
        sys.stdout = open('tcSol{}.txt'.format(f),'w')
        solve()

mksols(N)

"""
Today chef got elected as the president of chefland. to celebrate this he decided to gift t-shirts with his name written on it to the citizens of chefland. so he asked them to fill a form to get to know their t-shirt size.

after collecting the size data of the $N$ citizens, he ordered the same to a t-shirt making factory but on delivery, he finds that some of the t-shirts received do not match with the citizen's desired size.

you are supposed to help chef solve this issue by telling him whether it is possible or not to solve the issue by exchanging the t-shirts between the citizens.

print "YES" (without quotes) if it is possible to completely solve the issue

if it is not possible then print the number of citizens who will not get their t-shirt after
performing all possible exchanges.

###Input:

- First-line will contain $T$, the number of test cases. Then the test cases follow. 
- The first line of each test case contains $N$ the number of citizens, $N$ lines follow 
- each of these $N$ lines contains three space-separated values, an integer $i$ the citizen number , a character $x$ the size of t-shirt ordered by citizen $i$ and a character $y$ the size of the t-shirt received

###Output:
a single line containing the string $"YES"$ (without quotes) if it is possible to solve the issue otherwise an integer the number of citizens who will not get their t-shirt after
performing all possible exchanges.

###Constraints 
- $1 \leq T \leq 10^3$
- $2 \leq N \leq 10^3$
- $0 \leq i < N$
- $x$ and $y$ can be any uppercase character of the English alphabet

###Sample Input:
    1
    4
    0 S M
    1 M L
    2 M S
    3 L M


###Sample Output:
YES
	
###EXPLANATION:
citizen 0 can exchange his t-shirt with 2 and 1 can exchange with 3  

"""