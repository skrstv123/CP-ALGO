from collections import defaultdict as df
for _ in range(int(input())):
	n = int(input())
	s = list(map(int, input().split()))	
	ans = 0
	if n<=5:
		print(ans)
		continue
	dd = df(bool)
	for i in range(1, n-1):
		if s[i-1]<s[i]>s[i+1] or s[i-1]>s[i]<s[i+1]:
			dd[i] = True
			ans+=1 
	th= tw = o =False

	for i in range(1, n-1):
		if dd[i] and dd[i+1] and dd[i+2]:
			th = True
		elif dd[i] and dd[i+1]:
			tw = True
		elif dd[i]:
			o = True
	# print(dd)
	if th:
		ans-=3 
	elif tw:
		ans-=2
	elif o:
		ans-=1
	print(ans)

