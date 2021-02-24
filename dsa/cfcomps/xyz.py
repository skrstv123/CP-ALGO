from math import ceil
for _ in range(int(input())):
	n,k = map(int, input().split())
	k = list(map(int, input().split()))
	c = list(map(int, input().split()))
	i = 1 
	buy = set()
	ans = 0
	k.sort(reverse=1)
	for x in k:
		if i<=x:
			ans+=c[i-1]
			i+=1
		else:
			ans+=c[x-1]
	print(ans)