import sys
from collections import defaultdict
print = lambda x: sys.stdout.write(str(x)+'\n')
input = lambda : sys.stdin.readline()
ssi = lambda : list(map(int, input().split()))

cubevals = set(x*x*x for x in range(1, 10001))

for _ in range(int(input())):
    x = int(input())
    ans = "NO"
    for i in range(1, 10001):
        if x-i*i*i in cubevals:
            ans="YES"
            break
    print(ans)