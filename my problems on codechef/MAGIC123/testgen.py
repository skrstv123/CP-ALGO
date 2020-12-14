from random import randint
import sys
import bisect
import math

def maketf():
    tc = int(input('tc '))
    n, p, k = map(int, input('max n p k ').split())
    with open('tf'+input('enter tf no.: '), 'w') as tf:
        tf.write(str(tc)+'\n')
        for _ in range(tc):
            N,K = randint(1,n), randint(2, k)
            tf.write(f"{N} {K}\n")
            tf.write(' '.join([str(randint(1, p)) for _ in range(N)])+'\n')

def make_solf(fn):
    def solve():
        def find_lis(l):
            if len(l)==1:return l 
            lis = l[:1]
            for i in l[1:]:
                if i>lis[-1]:
                    lis.append(i)
                else:
                    lis[bisect.bisect_left(lis, i)] = i 
            return lis

        for _ in range(int(input())):
            n,k = map(int, input().split())
            p = list(map(int, input().split()))
            mp = max(p)

            mark = [True for _ in range(mp+1)]
            
            mark[0] = False

            for f in range(2, k+1):
                if f<=mp:
                    if mark[f]:
                        mark[f]=False
                        for x in range(f*f, mp+1, f):
                            mark[x] = False
            
            fin_p = [x for x in p if mark[x]]

            if len(fin_p):
                fin_p = find_lis(fin_p)
            
            print("YES" if len(fin_p)>=k else "NO")
    
    sys.stdin = open('tf'+str(fn),'r')
    sys.stdout = open('sf'+str(fn),'w')
    solve()

# maketf()

#  _                      _   _  __       _
# | |__   ___  __ _ _   _| |_(_)/ _|_   _| |
# | '_ \ / _ \/ _` | | | | __| | |_| | | | |
# | |_) |  __/ (_| | |_| | |_| |  _| |_| | |
# |_.__/ \___|\__,_|\__,_|\__|_|_|  \__,_|_|

#  _                _                                   _
# | |__   __ _  ___| | ____ _ _ __ ___  _   _ _ __   __| |
# | '_ \ / _` |/ __| |/ / _` | '__/ _ \| | | | '_ \ / _` |
# | |_) | (_| | (__|   < (_| | | | (_) | |_| | | | | (_| |
# |_.__/ \__,_|\___|_|\_\__, |_|  \___/ \__,_|_| |_|\__,_|
#                       |___/