from collections import defaultdict as dd
import sys 
sys.stdin = open('tcf1.txt','r')
def mysol():
    answers=[]
    for tc in range(int(input())):
        n = int(input())
        ordered = dd(list)
        received = dd(list)

        for i in range(n):
            i,o,r=input().split()
            ordered[o].append(int(i))
            received[r].append(int(i))

        fails = []
        for size in ordered.keys():
            if len(ordered[size])>len(received[size]):
                fails.extend(sorted(ordered[size][len(received[size]):]))

        if len(fails)==0: answers.append('YES') 
        else: 
            answers.append(sorted(fails))
    return answers

myans = mysol()
sys.stdin = open('tcf1.txt','r')
def akay():
    answers = []
    for _ in range(int(input())):
        n=int(input())
        dic={};stock={}
        for i in range(n):
            temp=list(input().split())
            dic[temp[0]]=temp[1]
            if(temp[2] in stock):
                stock[temp[2]]+=1
            else:
                stock[temp[2]]=1
        count=[]
        for i in sorted(dic.keys()):
            if(dic[i] not in stock.keys()) or stock[dic[i]]==0:
                count.append(i)
            else:
                stock[dic[i]]-=1
            
        if(len(count)==0):
            answers.append("YES")
        else:
            answers.append(count) 
    return answers

akaysol = akay()

for i in range(len(myans)):
    if akaysol[i]!=myans[i]:
        print(myans[i],akaysol[i])
        print(i+1)
        break