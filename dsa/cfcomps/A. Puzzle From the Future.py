import sys
input = lambda : sys.stdin.readline()
print = lambda x : sys.stdout.write(x + '\n')
for _ in range(int(input())):
    n = int(input())
    b = input()
    a = '1'
    if n>1:
        for i in range(1,n):
            if int(b[i-1]) + int(a[i-1]) != int(b[i]) + 1:
                a+='1'
            else:
                a+='0'
    print(a)
