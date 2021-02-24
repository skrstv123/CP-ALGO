for _ in range(int(input())):
    s = list(input())
    i=j=0 
    vis = [False]*len(s)
    n = len(s)
    while i<n and j<n:
        while i<n and vis[i]:
            i+=1
        if i<n:
            if s[i]=='a':
                s[i] = 'b' 
            else:
                s[i] = 'a'
            vis[i] = True
            i+=1 

        while j<n and vis[j]:
            j+=1
        if j<n:
            if s[j]=='z':
                s[j] = 'y' 
            else:
                s[j] = 'z'
            vis[j] = True
            j+=1 
    print(*s, sep='')