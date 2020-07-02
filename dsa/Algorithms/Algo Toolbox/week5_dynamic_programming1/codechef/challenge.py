# cook your dish here
from sys import stdin, stdout
def op(s): stdout.write(str(s)+'\n')
def ip(): return stdin.readline().strip()
import numpy as np 

def helper(ans, r, i, window_size, total_here):
    if window_size==1:
        ans[r, i] = 1
        
    ws = window_size>>1
    while total_here>0:
        for c in range(i, i+window_size, ws):
            if np.all(ans[r, c:c+ws]==1): continue
            # query the segment
            print(1, r+1, c+1, r+1, c+ws)
            segment_total = int(ip())

            if segment_total==0: continue
            if segment_total==ws: 
                ans[r, c:c+ws]= 1 
                total_here-=ws
                if total_here==0: return
        ws>>=1
        if ws==0: return

for _ in range(int(ip())):
    n,p = map(int, ip().split())
    ans = np.zeros((n,n),dtype = np.int8)

    if p==100:
        ans[:, :] = 1 
        print(2)
        for i in range(n):
            print(*ans[i,:])
        if int(ip())==-1: 
            break

    for r in range(n):
        # get total elms in a row 
        print(1,r+1,1,r+1,n)
        
        total_in_row = int(ip())
        
        #------------edge cases------------
        if total_in_row==0: continue
        if total_in_row==n: 
            ans[r, :] = 1
            continue
        #------------edge cases------------
        curr_window = n>>1 
        while total_in_row:
            for i in range(0,n,curr_window):
                # dont query if all elements were already found
                if np.all(ans[r, i:i+curr_window]==1): continue
                
                # query the segment
                print(1, r+1, i+1, r+1, i+curr_window)
                segment_total = int(ip())


                #------edge cases------------

                #donot search in other sgements if current segment has all the elements
                if segment_total==total_in_row:
                    # print('helper called-')
                    helper(ans, r, i, curr_window, segment_total)
                    total_in_row=curr_window=0
                    break

                if segment_total==0: continue
                if segment_total==curr_window: 
                    ans[r, i:i+curr_window]= 1 
                    total_in_row-=curr_window
                    if total_in_row==0: break
                    
                #------edge cases------------
                
            curr_window>>=1 
            if curr_window==0: total_in_row=0 
            
    # print the result 
    print(2)
    for i in range(n):
        print(*ans[i,:])
                
    if int(ip())==-1: 
        break