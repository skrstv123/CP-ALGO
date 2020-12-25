Bob just learned about bitwise operators. Since Alice is an expert, she decided to play a game, she will give a number $x$ to Bob and will ask some questions:

There will be 5 different kinds of queries:-

1. Alice gives an integer $i$ and Bob has to tell the status of the $i^{th}$ bit, the answer is $"ON"$ if it is on else $"OFF"$.
2. Alice gives an integer $i$ and Bob has to turn on the $i^{th}$ bit and then tell the value of $x$.
3. Alice gives an integer $i$ and Bob has to turn off the $i^{th}$ bit and then tell the value of $x$.
4. Alice gives an integer $p$ and in the decimal representation of $x$ Bob has to tell the $p^{th}$ digit.
5. Alice gives two integers $p$ and $q$ and in the decimal representation of $x$ Bob has to replace the $p^{th}$ digit with $q$ and then tell the value of $x$.

The value of $x$ changes after any update operation.

###Input:

- First line will contain $T$, number of testcases. Then the testcases follow. 
- the first line of each testcase contains of a single line of input, two integers $x, Q$.
- $q$ lines follow.
- for each query of type 1 to 4, there will be two space-separated integers, the query type and the integer $i$
- for the query of type 5, there will be three space-separated integers, the query type, and the integers $p, q$

###Output:
For the query of the first kind, print either $"ON"$ or $"OFF"$, and for the rest of the queries print the value of $x$. 

###Constraints 
- $1 \leq T \leq 10^4$
- $1 \leq x \leq 10^9$
- $1 \leq Q \leq 10^5$
- $1 \leq i \leq 30$
- $1 \leq p \leq 10$
- $0 \leq q \leq 9$

###Sample Input
```
	1
	2 2
	1 1
	2 1
```

###Sample Output:
```
	OFF
	3
```
	
###EXPLANATION:
```
the binary representation of 2 is 10
for query 1, since the bit at the first position is 0, the answer is OFF.
for the next query, After turning on the first bit, the value of $x$ becomes 3 (or 11 in binary).
```
