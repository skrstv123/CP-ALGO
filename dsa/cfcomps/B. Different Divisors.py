# from itertools import combinations as c

for _ in range(int(input())):
    d = int(input())
    num = 1 
    dd = 1
    for i in range(2):
        dd+=d 
        num*=dd  
    print(num)

    
