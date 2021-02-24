Bob just learned about bitwise operators. Since Alice is an expert, she decided to play a game, she will give a number $x$ to Bob and will ask some questions:

There will be 5 different kinds of queries:-

1. Alice gives an integer $i$ and Bob has to report the status of the $i^{th}$ bit, the answer is $"ON"$ if it is on else $"OFF"$.
   
2. Alice gives an integer $i$ and Bob has to turn on the $i^{th}$ bit.
   
3. Alice gives an integer $i$ and Bob has to turn off the $i^{th}$ bit.
      
4. Alice gives two integers $p$ and $q$ and in the binary representation of $x$ Bob has to swap the $p^{th}$ and the $q^{th}$ bits.

The value of $x$ changes after any update operation.

positions $i$, $p$ and $q$ are always counted from right or from the least significant bit.

###Input:

- First line will contain $T$, number of testcases. Then the testcases follow. 
- the first line of each testcase contains two space-separated integers $x, Q$.
- $2Q$ lines follow.
- first line is an integer, the query type.
- for each query of type 1 to 3, there will be the integer $i$
- for the query of type 4, there will be two space-separated integers,the integers $p, q$

###Output:
For the queries of the first kind, print $"ON"$ or $"OFF"$.

###Constraints 
- $1 \leq T \leq 10^3$
- $1 \leq x \leq 10^9$
- $1 \leq Q \leq 10^3$
- $1 \leq i,p,q \leq 30$

###Sample Input
```
	1
	2 2
	2 
	1
	1 
	1
```

###Sample Output:
```
	ON
```
	
###EXPLANATION:
```
the binary representation of 2 is 10
for query 1, we just have to update x to 11 (or 3 in decimal).
for the next query, x is now 3 or 11 in binary so answer is ON.
```
