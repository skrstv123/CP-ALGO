# import sys
# sys.stdin=open('ip.txt','r')

# m=int(input())
# s=0 
# s+=(m//10)
# m%=10
# s+=(m//5)
# m%=5
# s+=m 
# print(s)

# n,w=map(int,input().split())
# pl=[]
# for i in range(n):
#     p,m=map(int,input().split())
#     pl.append([p/m,m])
# pl.sort(key=lambda x: x[0],reverse=1)
# a=0
# for p,m in pl:
#     if w:
#         if m>=w:
#             a+=(p*w)
#             w=0 
#         else:
#             w-=m 
#             a+=(p*m)
#     else: break 
# print('{:.4f}'.format(a))
def comparator(a, b): 
    ab = str(a) + str(b) 
    ba = str(b) + str(a) 
    return ((int(ba) > int(ab)) - (int(ba) < int(ab)))   
# n=int(input())
# l=list(map(int,input().split()))
# m=list(map(int,input().split()))
# l.sort()
# m.sort()
# s=0 
# for i,j in zip(l,m):
#     s+=i*j 
# print(s)

# class seg:
#     def __init__(self,a,b):
#         self.a=a;self.b=b;
# n=int(input())
# sg=[]
# for i in range(n):
#     a,b=map(int,input().split())
#     sg.append(seg(a,b))
# sg.sort(key=lambda x: x.b) 
# mk=[]
# while sg:
#     s=sg.pop(0)
#     mr=s.b
#     while sg and sg[0].b>=s.b and sg[0].a<=s.b:
#         sg.pop(0)
#     mk.append(mr)
# print(len(mk))
# print(*mk)
def m(mycmp):  
    class K(object): 
        def __init__(self, obj, *args): 
            self.obj = obj 
        def __lt__(self, other): 
            return mycmp(self.obj, other.obj) < 0
        def __gt__(self, other): 
            return mycmp(self.obj, other.obj) > 0
        def __eq__(self, other): 
            return mycmp(self.obj, other.obj) == 0
        def __le__(self, other): 
            return mycmp(self.obj, other.obj) <= 0
        def __ge__(self, other): 
            return mycmp(self.obj, other.obj) >= 0
        def __ne__(self, other): 
            return mycmp(self.obj, other.obj) != 0
    return K 
 
#max pw distinct
# n=int(input())
# x=1
# l=[]
# while n:
#     if n-x>x:
#         l.append(x)
#         n-=x 
#         x+=1
#     else:
#         l.append(n)
#         break
# print(len(l))
# print(*l)


l=input()
a=list(map(int,input().split()))
sor = sorted(a, key=m(comparator)) 
number = "".join([str(i) for i in sor]) 
print(number) 
