import heapq
from random import randint as ri
l = [ri(1,100) for i in range(100)]

#--------------heap sort -> heapify---------
heapq.heapify(l) 
#this is a min heap 
# print(l)

# ------------inserting into the heap -> heappush-------
heapq.heappush(l,0) #should come at root

#print(l)

#--------------printing nsmallest and nlargest------------------
#more efficient than min max
# print(heapq.nsmallest(3,l),heapq.nlargest(3,l))

#--------------popping elements in ascending order-----------
#much efficient than sorting
x=[]
while l:
	x.append(heapq.heappop(l))

# print(x==sorted(x)) #is true