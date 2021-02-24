for i in range(int(input())):
    n = int(input())
    x = n%2020
    if (n-2021*x)>=0 and (n-2021*x)%2020==0 and n>=2020:
        print("YES")
    else:
        print("NO")
