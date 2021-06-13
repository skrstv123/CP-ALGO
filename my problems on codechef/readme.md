# MAGICAL BULLETS (encoding nov'20)

```
Chef is planning to eliminate the ghosts from his house with the help of some magical bullets he has. Each bullet has some power level $P_i$. A ghost can sometimes destroy the magical bullets if it possesses any of the skill S in the range 2 to K (both inclusive) such that S is a factor of $P_i$.

Given the set of guns (the power of the guns), Chef is having and chef wants to pick only those guns such that the ghost cannot destroy the bullet. Also whenever Chef picks up another gun the power level of this gun should be strictly greater than the previously used gun. He also does not want to alter the order of guns.

A ghost is eliminated only when the sum of powers of bullets it is shot with is greater than or equal to a value X.

Given the powers of guns, the value of K, and the value of X for a ghost find out whether this ghost can be killed or not.

## input 
- first line contains $t$ number of test cases
- first line of each test-case contains three space separated integers $N,K,X$
- second line of each test-case contains $N$ space separated integers, $P_i$

## output
for each test-case, print "YES" if ghost can be killed ,else "NO"

## constraints
- $1 \leq T \leq 10^2$
- $1 \leq N,X \leq 10^5$
- $2 \leq K \leq 10^4$
- $1 \leq P_i \leq 10^5$

## example input
1
5 4 3
1 9 5 7 2

## example output
YES

## explanation
chef can pick bullets 1,5,7
```

# Help the President (encoding junior may'20)
```
Today Chef got elected as the president of chefland. to celebrate this he decided to gift t-shirts with his name written on it to the citizens of chefland. so he asked them to fill a form to get to know their t-shirt size.

after collecting the size data of the $N$ citizens, he ordered the same to a t-shirt making factory but on delivery, he finds that some of the t-shirts received do not match with the citizen's desired size.

Neither the president nor the citizens are happy with this and Chef clearly don't want to lose the next elections due to this. Chef's old friend Cheftor suggested to him that it might be possible to solve the issue if the citizen's exchange their t-shirts, however, the citizens with smaller ID number are always given higher priority so if it is possible the issue must be solved for the citizens with a smaller ID number first.

you are supposed to help chef solve this issue by telling him whether it is possible or not to solve the issue by exchanging the t-shirts between the citizens.

If the issue cannot be solved completely then Chef wants to know the total number of those unlucky citizens and their ID numbers so that he can reorder t-shirts for them.

###Input:

- First-line will contain $T$, the number of test cases. Then the test cases follow. 
- The first line of each test case contains $N$ the number of citizens, $N$ lines follow 
- each of these $N$ lines contains three space-separated values, an integer $i$ the citizen ID number(each citizen has an unique ID), a character $x$ the size of t-shirt ordered by citizen $i$ and a character $y$ the size of the t-shirt received

###Output:
print a single line containing the string $"YES"$ (without quotes) if it is possible to solve the issue 
otherwise print two lines, the first line contains an integer the number of citizens who will not get their t-shirt after performing all possible exchanges. In the next line print their ID numbers <strong>in increasing order</strong> separated by a space.

###Constraints 
- $1 \leq T \leq 10^3$
- $2 \leq N \leq 10^3$
- $0 \leq i < N$
- $x$ and $y$ can be any uppercase letter of the English alphabet

###Sample Input:
    2
    4
    0 S M
    1 M L
    2 M S
    3 L M
    4
    0 A B
    1 A D
    2 A A
    3 E A


###Sample Output:
    YES
    2
    2 3
	
###EXPLANATION:
<U>CASE 1</U>
citizen 0 can exchange his t-shirt with 2 and 1 can exchange with 3  

<U>CASE 2</U>
T-shirt of size A was ordered by the first 3 citizens and the 4th citizen wanted a t-shirt of size E but we have only 2 t-shirts of size A and no one received a t-shirt of size E.
So only the first two citizens (with smallest ID numbers) will get the t-shirts of the desired size.
```
# How can sum one run (encoding jr march'21)
```
Chef junior recently learnt to code. Today he successfully compiled a code which takes in a stream of integers and prints the running sum.

for example, if the input is $1,2,3,4,5$ then his prgram prints $1,3,6,10,15$. 

Chef junior's code was very simple, he initialised a variable $sum$ with $0$ and on reading an integer input he simply added it to the $sum$ variable and printed it.

His coach Cheflatoon challenged him to find the minimum initial value of the varible $sum$ so that the running sum is never less than $1$.

for example, if the input stream is: $1,2,-3,4,5$ then the answer will be $1$. Since Chef junior is a beginner he needs your help to solve this problem.


###Input:

- First line will contain $T$, number of testcases. Then the testcases follow. 
- First line of each testcase contains $n$, the number of integers in the stream.
- Second line of each testcase contains $n$ space-separated integers $e_i$.

###Output:
For each testcase, output in a single line, the minimum initial value of the varible $sum$ so that the running sum is never less than $1$. 

###Constraints 
- $1 \leq T \leq 100$
- $1 \leq N \leq 10^3$
- $- 10^3 \leq e_i \leq 10^3$

###Sample Input:
	1
	5
	1 2 -3 4 5 

###Sample Output:
	1
	
###EXPLANATION:
if we initialise $sum$ with $1$ instead of $0$, the running sum will be $2,3,1,5,10$.
```

# Status and Updates (encoding dec'20)
```
Bob just learned about bitwise operators. Since Alice is an expert, she decided to play a game, she will give a number $x$ to Bob and will ask some questions:

There will be 4 different kinds of queries:-

1. Alice gives an integer $i$ and Bob has to report the status of the $i^{th}$ bit in $x$, the answer is $"ON"$ if it is on else $"OFF"$.
   
2. Alice gives an integer $i$ and Bob has to turn on the $i^{th}$ bit in $x$.
   
3. Alice gives an integer $i$ and Bob has to turn off the $i^{th}$ bit in $x$.
      
4. Alice gives two integers $p$ and $q$ and in the binary representation of $x$ Bob has to swap the $p^{th}$ and the $q^{th}$ bits.

The value of $x$ changes after any update operation.

positions $i$, $p$, and $q$ are always counted from the right or from the least significant bit.

If anyone of $i$, $p$, or $q$ is greater than the number of bits in the binary representation of $x$, consider $0$ at that position.

###Input:

- First-line will contain $T$, the number of test cases. Then the test cases follow. 
- the first line of each test case contains two space-separated integers $x, Q$.
- $2Q$ lines follow.
- first line is an integer, the query type.
- for each query of type 1 to 3, there will be the integer $i$
- for the query of type 4, there will be two space-separated integers, the integers $p, q$

###Output:
For the queries of the first kind, print $"ON"$ or $"OFF"$.

###Constraints 
- $1 \leq T \leq 10^3$
- $1 \leq x \leq 10^9$
- $1 \leq Q \leq 10^3$
- $1 \leq i,p,q \leq 30$

###Sample Input
	1
	2 2
	2 
	1
	1 
	1

###Sample Output:
	ON
	
###EXPLANATION:
the binary representation of 2 is 10
for query 1, we just have to update x to 11 (or 3 in decimal).
for the next query, x is now 3 or 11 in binary so the answer is ON.

```

# technological singularity (encoding jr mar'20)
```
Today Chef met his old friend Cheftor who is currently working on Artificial Intelligence (AI in short) which can predict the temperature of any place.  

He asks the Chef to help him evaluate the performance of the AI by comparing the actual temperature with the temperature predicted by the AI. However Chef and Cheftor both know that the temperature predicted by the AI cannot be accurate always, so they decided to allow a minimum error in the predicted values.

Given the values of actual temperature $t$, the predicted temperature $p$ and the minimum error allowed $e$, if the difference between the predicted value and the actual value is <i> less than or equal </i> to the allowed minimum error then AI passes the evaluation otherwise not.

Print a single line containing the string "PASSED" (without quotes) if the AI passed the test otherwise print "FAILED" (without quotes). 

Note that the output should be in upper case only. "passed", "Passed" or any such output will receive the wrong answer verdict.


###Input:<hr>
- First line will contain $T$, number of testcases. Then the testcases follow. 

- Each testcase contains three space separated integers $t$ , $p$ and $e$ for the actual temperature, temperature predicted by the AI and the minimum allowed error respectively


###Output:<hr>
For each testcase, print a single line containing the string "PASSED" (without quotes) if the AI passed the test otherwise print "FAILED" (without quotes)


###Constraints <hr>
- $1 \leq T \leq 10$
- $0 \leq t \leq 100$
- $0 \leq p \leq 100$
- $0 \leq e \leq 10$



###Sample Input:<hr>
    2
    25 20 5
    80 100 10



###Sample Output:<hr>
    PASSED
    FAILED

	

###EXPLANATION:<hr>
For the first test case
the  error is $25 - 20 = 5$ 
and since $5\leq5$ the AI passed this test


For the second test case
the absolute error is $100-80 = 20$ 
and since $20\leq10$ is not true the AI fails 
```
