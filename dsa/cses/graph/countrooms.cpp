#include <bits/stdc++.h>
bool mark[1000][1000];
char map[1000][1000];

void dffs(int x, int y, int m, int n){
    mark[x][y]=true;
    
    if(y>0)
    if(map[x][y-1]=='.' && mark[x][y-1]==false)dffs(x,y-1,m,n);
    
    if(y+1<n)
    if(map[x][y+1]=='.' && mark[x][y+1]==false)dffs(x,y+1,m,n);
    
    if(x>0)
    if(map[x-1][y]=='.' && mark[x-1][y]==false)dffs(x-1,y,m,n);
    
    if(x+1<m)
    if(map[x+1][y]=='.' && mark[x+1][y]==false)dffs(x+1,y,m,n);
}

int main()
{
    int n,m, count=0;
    std::cin >> m>>n;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    std::cin>>map[i][j];
    
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        if(map[i][j]=='.' && mark[i][j]==false){
            count++;
            dffs(i,j,m,n);
        }
    }
    std::cout << count << std::endl;   
}
