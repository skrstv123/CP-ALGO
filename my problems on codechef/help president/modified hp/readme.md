#HELP THE PRESIDENT

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
