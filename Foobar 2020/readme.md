# GOOGLE FOOBAR 2020

## LEVEL 1

Re-ID
=====

There's some unrest in the minion ranks: minions with ID numbers like "1", "42", and other "good" numbers have been lording it over the poor minions who are stuck with more boring IDs. To quell the unrest, Commander Lambda has tasked you with reassigning everyone new, random IDs based on her Completely Foolproof Scheme.

She's concatenated the prime numbers in a single long string: "2357111317192329...". Now every minion must draw a number from a hat. That number is the starting index in that string of primes, and the minion's new ID number will be the next five digits in the string. So if a minion draws "3", their ID number will be "71113".

Help the Commander assign these IDs by writing a function answer(n) which takes in the starting index n of Lambda's string of all primes, and returns the next five digits in the string. Commander Lambda has a lot of minions, so the value of n will always be between 0 and 10000.

Languages
========= 

To provide a Python solution, edit solution.py To provide a Java solution, edit solution.java

Test cases
==========

Inputs: (int) n = 0 Output: (string) "23571"

Inputs: (int) n = 3 Output: (string) "71113"

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.

```python
from math import sqrt
def ps(n):
    pr=[True]*(n+1)
    primes=  []
    pr[0] = pr[1] = False
    for i in range(2,int(sqrt(n))+1):
        if pr[i]:
            primes.append(str(i))
            for j in range(i*i, n, i):
                pr[j]= False
    return ''.join(primes)

def solution(n):
    pstr = ps(25000)
    return pstr[n:n+5]            
```

## LEVEL 2

- - -

Elevator Maintenance
====================

You've been assigned the onerous task of elevator maintenance - ugh! It wouldn't be so bad, except that all the elevator documentation has been lying in a disorganized pile at the bottom of a filing cabinet for years, and you don't even know what elevator version numbers you'll be working on. 

Elevator versions are represented by a series of numbers, divided up into major, minor and revision integers. New versions of an elevator increase the major number, e.g. 1, 2, 3, and so on. When new features are added to an elevator without being a complete new version, a second number named "minor" can be used to represent those new additions, e.g. 1.0, 1.1, 1.2, etc. Small fixes or maintenance work can be represented by a third number named "revision", e.g. 1.1.1, 1.1.2, 1.2.0, and so on. The number zero can be used as a major for pre-release versions of elevators, e.g. 0.1, 0.5, 0.9.2, etc (Commander Lambda is careful to always beta test her new technology, with her loyal henchmen as subjects!).

Given a list of elevator versions represented as strings, write a function solution(l) that returns the same list sorted in ascending order by major, minor, and revision number so that you can identify the current elevator version. The versions in list l will always contain major numbers, but minor and revision numbers are optional. If the version contains a revision number, then it will also have a minor number.

For example, given the list l as ["1.1.2", "1.0", "1.3.3", "1.0.12", "1.0.2"], the function solution(l) would return the list ["1.0", "1.0.2", "1.0.12", "1.1.2", "1.3.3"]. If two or more versions are equivalent but one version contains more numbers than the others, then these versions must be sorted ascending based on how many numbers they have, e.g ["1", "1.0", "1.0.0"]. The number of elements in the list l will be at least 1 and will not exceed 100.

Languages
=========

To provide a Python solution, edit solution.py
To provide a Java solution, edit Solution.java

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Python cases --
Input:
solution.solution(["1.11", "2.0.0", "1.2", "2", "0.1", "1.2.1", "1.1.1", "2.0"])
Output:
    0.1,1.1.1,1.2,1.2.1,1.11,2,2.0,2.0.0

Input:
solution.solution(["1.1.2", "1.0", "1.3.3", "1.0.12", "1.0.2"])
Output:
    1.0,1.0.2,1.0.12,1.1.2,1.3.3

-- Java cases --
Input:
Solution.solution({"1.11", "2.0.0", "1.2", "2", "0.1", "1.2.1", "1.1.1", "2.0"})
Output:
    0.1,1.1.1,1.2,1.2.1,1.11,2,2.0,2.0.0

Input:
Solution.solution({"1.1.2", "1.0", "1.3.3", "1.0.12", "1.0.2"})
Output:
    1.0,1.0.2,1.0.12,1.1.2,1.3.3

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.



```python
class v:
    def __init__(self,l):
        self.le = len(l)
        self.l = l 
    
    def __lt__(self, other):
        l1 = self.l
        l2 = other.l 
        
        if l1[0]!=l2[0]: return l1[0]<l2[0] 
        if self.le>1 and other.le>1: 
            if l1[1]!=l2[1]: return l1[1]<l2[1] 

        if self.le>2 and other.le>2:
            if l1[2]!=l2[2]: return l1[2]<l2[2]
            
        return self.le<other.le
            
    def __gt__(self,other):
        
        l1 = self.l
        l2 = other.l 
        
        if l1[0]!=l2[0]: return l1[0]>l2[0] 
        if self.le>1 and other.le>1: 
            if l1[1]!=l2[1]: return l1[1]>l2[1] 
            
        if self.le>2 and other.le>2:
            if l1[2]!=l2[2]: return l1[2]>l2[2]
            
        return self.le>other.le
        
def solution(l):
    # Your code here
    l=[v(list(map(int,x.split('.')))) for x in l]
    l.sort()
    l=['.'.join(list(map(str,x.l))) for x in l]
    return l
```

- - -

Please Pass the Coded Messages
==============================

You need to pass a message to the bunny prisoners, but to avoid detection, the code you agreed to use is... obscure, to say the least. The bunnies are given food on standard-issue prison plates that are stamped with the numbers 0-9 for easier sorting, and you need to combine sets of plates to create the numbers in the code. The signal that a number is part of the code is that it is divisible by 3. You can do smaller numbers like 15 and 45 easily, but bigger numbers like 144 and 414 are a little trickier. Write a program to help yourself quickly create large numbers for use in the code, given a limited number of plates to work with.

You have L, a list containing some digits (0 to 9). Write a function solution(L) which finds the largest number that can be made from some or all of these digits and is divisible by 3. If it is not possible to make such a number, return 0 as the solution. L will contain anywhere from 1 to 9 digits.  The same digit may appear multiple times in the list, but each element in the list may only be used once.

Languages
=========

To provide a Java solution, edit Solution.java
To provide a Python solution, edit solution.py

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Java cases --
Input:
Solution.solution({3, 1, 4, 1})
Output:
    4311

Input:
Solution.solution({3, 1, 4, 1, 5, 9})
Output:
    94311

-- Python cases --
Input:
solution.solution([3, 1, 4, 1])
Output:
    4311

Input:
solution.solution([3, 1, 4, 1, 5, 9])
Output:
    94311

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.



```python
def solution(l):
    # Your code here
    l.sort(reverse = 1)
    s=sum(l)
    if s%3==0: 
        return ''.join([str(c) for c in l])
    else:  
        # search for num with rem eqto rem of sum and del it
        r=s%3 
        td = None
        for i in range(len(l)-1,-1,-1):
            if l[i]%3 == r:
                td = i 
                break 
        if td is not None:
            l=l[:i]+l[i+1:]
            return ''.join([str(c) for c in l]) 
        # if no such nmbr was found 
        # del 2 nos with rem 3-r 
        r=3-r 
        nc= 0 
        td=[]
        for i in range(len(l)-1,-1,-1):
            if l[i]%3 == r:
                td.append(i)
                nc+=1
                if nc==2: 
                    break 
        if len(td)==2 and len(l)>2: 
            return ''.join([str(l[xxx]) for xxx in range(len(l)) if xxx not in td])
        else:
            return '0'
```

To invite a friend to try a challenge, send the link below. This is a single-use code, so choose wisely.

Refer a friend: "" (used)


## LEVEL 3

- - -

The Grandest Staircase Of Them All
==================================

With her LAMBCHOP doomsday device finished, Commander Lambda is preparing for her debut on the galactic stage - but in order to make a grand entrance, she needs a grand staircase! As her personal assistant, you've been tasked with figuring out how to build the best staircase EVER. 

Lambda has given you an overview of the types of bricks available, plus a budget. You can buy different amounts of the different types of bricks (for example, 3 little pink bricks, or 5 blue lace bricks). Commander Lambda wants to know how many different types of staircases can be built with each amount of bricks, so she can pick the one with the most options. 

Each type of staircase should consist of 2 or more steps.  No two steps are allowed to be at the same height - each step must be lower than the previous one. All steps must contain at least one brick. A step's height is classified as the total amount of bricks that make up that step.
For example, when N = 3, you have only 1 choice of how to build the staircase, with the first step having a height of 2 and the second step having a height of 1: (# indicates a brick)

```
#
##
21

When N = 4, you still only have 1 staircase choice:

#
#
##
31
 
But when N = 5, there are two ways you can build a staircase from the given bricks. The two staircases can have heights (4, 1) or (3, 2), as shown below:

#
#
#
##
41

#
##
##
32
```

Write a function called solution(n) that takes a positive integer n and returns the number of different staircases that can be built from exactly n bricks. n will always be at least 3 (so you can have a staircase at all), but no more than 200, because Commander Lambda's not made of money!

Languages
=========

To provide a Java solution, edit Solution.java
To provide a Python solution, edit solution.py

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Java cases --
Input:
Solution.solution(3)
Output:
    1

Input:
Solution.solution(200)
Output:
    487067745

-- Python cases --
Input:
solution.solution(200)
Output:
    487067745

Input:
solution.solution(3)
Output:
    1

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.



```python
from collections import defaultdict as dp
def KNAPSACK01(W):
    tbl=dp(lambda:0)
    tbl[0,0]= tbl[1,1] = tbl[2,2] = 1 
    for j in range(1,W):
        for i in range(W+1):
            tbl[i,j]=tbl[i,j-1]
            if i>=j:
                tbl[i,j]+=tbl[i-j,j-1]
    return tbl[W,W-1]
def solution(n):
    # Your code here
    return KNAPSACK01(n)
```
- - - 

Doomsday Fuel
=============

Making fuel for the LAMBCHOP's reactor core is a tricky process because of the exotic matter involved. It starts as raw ore, then during processing, begins randomly changing between forms, eventually reaching a stable form. There may be multiple stable forms that a sample could ultimately reach, not all of which are useful as fuel. 

Commander Lambda has tasked you to help the scientists increase fuel creation efficiency by predicting the end state of a given ore sample. You have carefully studied the different structures that the ore can take and which transitions it undergoes. It appears that, while random, the probability of each structure transforming is fixed. That is, each time the ore is in 1 state, it has the same probabilities of entering the next state (which might be the same state).  You have recorded the observed transitions in a matrix. The others in the lab have hypothesized more exotic forms that the ore can become, but you haven't seen all of them.

Write a function solution(m) that takes an array of array of nonnegative ints representing how many times that state has gone to the next state and return an array of ints for each terminal state giving the exact probabilities of each terminal state, represented as the numerator for each state, then the denominator for all of them at the end and in simplest form. The matrix is at most 10 by 10. It is guaranteed that no matter which state the ore is in, there is a path from that state to a terminal state. That is, the processing will always eventually end in a stable state. The ore starts in state 0. The denominator will fit within a signed 32-bit integer during the calculation, as long as the fraction is simplified regularly. 

For example, consider the matrix m:
[
  [0,1,0,0,0,1],  # s0, the initial state, goes to s1 and s5 with equal probability
  [4,0,0,3,2,0],  # s1 can become s0, s3, or s4, but with different probabilities
  [0,0,0,0,0,0],  # s2 is terminal, and unreachable (never observed in practice)
  [0,0,0,0,0,0],  # s3 is terminal
  [0,0,0,0,0,0],  # s4 is terminal
  [0,0,0,0,0,0],  # s5 is terminal
]
So, we can consider different paths to terminal states, such as:
s0 -> s1 -> s3
s0 -> s1 -> s0 -> s1 -> s0 -> s1 -> s4
s0 -> s1 -> s0 -> s5
Tracing the probabilities of each, we find that
s2 has probability 0
s3 has probability 3/14
s4 has probability 1/7
s5 has probability 9/14
So, putting that together, and making a common denominator, gives an answer in the form of
[s2.numerator, s3.numerator, s4.numerator, s5.numerator, denominator] which is
[0, 3, 2, 9, 14].

Languages
=========

To provide a Java solution, edit Solution.java
To provide a Python solution, edit solution.py

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Java cases --
Input:
Solution.solution({{0, 2, 1, 0, 0}, {0, 0, 0, 3, 4}, {0, 0, 0, 0, 0}, {0, 0, 0, 0,0}, {0, 0, 0, 0, 0}})
Output:
    [7, 6, 8, 21]

Input:
Solution.solution({{0, 1, 0, 0, 0, 1}, {4, 0, 0, 3, 2, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}})
Output:
    [0, 3, 2, 9, 14]

-- Python cases --
Input:
solution.solution([[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0,0], [0, 0, 0, 0, 0]])
Output:
    [7, 6, 8, 21]

Input:
solution.solution([[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]])
Output:
    [0, 3, 2, 9, 14]

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.


[Tutorial](https://www.youtube.com/watch?v=bTeKu7WdbT8)

```python
# -------------------DOOMSDAY FUEL-------------------------
# BASED ON :- MARKOV ABSORBIBG CHAINS
#   --------------------------------------
def composer(m, rows, cols):
    new_matrix = []
    for row in rows:
        current_row = []
        for col in cols:
            current_row.append(m[row][col])
        new_matrix.append(current_row)
    return new_matrix
def compose_q(m, non_terminal_states):return composer(m, non_terminal_states, non_terminal_states)
def compose_r(m, non_terminal_states, terminal_states):return composer(m, non_terminal_states, terminal_states)
from fractions import gcd, Fraction
def listinp(func= int): return list(map(func,input().split())) 
def matrixMul(X,Y):
    result=[[0]*len(Y[0]) for _ in range(len(X))]
    for i in range(len(X)):
        for j in range(len(Y[0])):
            for k in range(len(Y)):
                result[i][j] += X[i][k] * Y[k][j]
    return result 

def transposeMatrix(m):
    return map(list,zip(*m))

def getMatrixMinor(m,i,j):
    return [row[:j] + row[j+1:] for row in (m[:i]+m[i+1:])]

def getMatrixDeternminant(m):
    #base case for 2x2 matrix
    if len(m) == 2:
        return m[0][0]*m[1][1]-m[0][1]*m[1][0]

    determinant = 0
    for c in range(len(m)):
        determinant += ((-1)**c)*m[0][c]*getMatrixDeternminant(getMatrixMinor(m,0,c))
    return determinant

def getMatrixInverse(m):
    determinant = getMatrixDeternminant(m)
    if len(m) == 2:
        return [[Fraction(m[1][1], determinant), Fraction(-1*m[0][1],determinant)],
                [Fraction(-1*m[1][0],determinant),Fraction( m[0][0], determinant)]]

    #find matrix of cofactors
    cofactors = []
    for r in range(len(m)):
        cofactorRow = []
        for c in range(len(m)):
            minor = getMatrixMinor(m,r,c)
            cofactorRow.append(((-1)**(r+c)) * getMatrixDeternminant(minor))
        cofactors.append(cofactorRow)
    cofactors = transposeMatrix(cofactors)
    for r in range(len(cofactors)):
        for c in range(len(cofactors)):
            cofactors[r][c] = Fraction(cofactors[r][c], determinant)
    return cofactors

def lcm(l):
    lc=l[0]
    def lcm2(a,b): return (a*b)//gcd(a,b)
    for x in l[1:]:
        lc=lcm2(lc,x)
    return lc 

def process_ans(l):
    dnms = lcm([x.denominator for x in l])
    nums= [x.numerator*dnms//x.denominator for x in l]
    nums.append(dnms)
    return nums

def solution(l):
    tsi=[]
    ntsi=[]
    for i in range(len(l)):
        ss=sum(l[i])
        if ss==0:
            l[i][i]=1
            tsi.append(i)
        else: 
            ntsi.append(i)
            for j in range(len(l)):
                l[i][j]=Fraction(l[i][j],ss)

    if len(tsi)==1: return [1,1]
    mat_R = compose_r(l, ntsi, tsi)
    mat_Q = compose_q(l, ntsi)
    for i in range(len(mat_Q)):
        for j in range(len(mat_Q)):
            mat_Q[i][j]=1- mat_Q[i][j] if i==j else -mat_Q[i][j]
    mat_Q_inv_F = getMatrixInverse([list(r) for r in mat_Q])
    mat_FR = matrixMul([list(r) for r in mat_Q_inv_F] , [list(r) for r in mat_R])
    return process_ans(mat_FR[0])
   
```

- - -

Bomb, Baby!
===========

You're so close to destroying the LAMBCHOP doomsday device you can taste it! But in order to do so, you need to deploy special self-replicating bombs designed for you by the brightest scientists on Bunny Planet. There are two types: Mach bombs (M) and Facula bombs (F). The bombs, once released into the LAMBCHOP's inner workings, will automatically deploy to all the strategic points you've identified and destroy them at the same time. 

But there's a few catches. First, the bombs self-replicate via one of two distinct processes: 
Every Mach bomb retrieves a sync unit from a Facula bomb; for every Mach bomb, a Facula bomb is created;
Every Facula bomb spontaneously creates a Mach bomb.

For example, if you had 3 Mach bombs and 2 Facula bombs, they could either produce 3 Mach bombs and 5 Facula bombs, or 5 Mach bombs and 2 Facula bombs. The replication process can be changed each cycle. 

Second, you need to ensure that you have exactly the right number of Mach and Facula bombs to destroy the LAMBCHOP device. Too few, and the device might survive. Too many, and you might overload the mass capacitors and create a singularity at the heart of the space station - not good! 

And finally, you were only able to smuggle one of each type of bomb - one Mach, one Facula - aboard the ship when you arrived, so that's all you have to start with. (Thus it may be impossible to deploy the bombs to destroy the LAMBCHOP, but that's not going to stop you from trying!) 

You need to know how many replication cycles (generations) it will take to generate the correct amount of bombs to destroy the LAMBCHOP. Write a function solution(M, F) where M and F are the number of Mach and Facula bombs needed. Return the fewest number of generations (as a string) that need to pass before you'll have the exact number of bombs necessary to destroy the LAMBCHOP, or the string "impossible" if this can't be done! M and F will be string representations of positive integers no larger than 10^50. For example, if M = "2" and F = "1", one generation would need to pass, so the solution would be "1". However, if M = "2" and F = "4", it would not be possible.

Languages
=========

To provide a Java solution, edit Solution.java
To provide a Python solution, edit solution.py

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Java cases --
Input:
Solution.solution('2', '1')
Output:
    1

Input:
Solution.solution('4', '7')
Output:
    4

-- Python cases --
Input:
solution.solution('4', '7')
Output:
    4

Input:
solution.solution('2', '1')
Output:
    1

```python
from math import gcd
def sol(a,b):
    if gcd(a,b)!=1: 
        return 'impossible'
    x=0
    while 1:
        if a<1 or b<1:
            return x-1 
        if a>b:
            x+=a//b 
            a%=b 
        elif b>a:
            x+=b//a 
            b%=a 
        
def solution(x, y):
    ans = str(sol(int(x),int(y)))
    return ans
```
