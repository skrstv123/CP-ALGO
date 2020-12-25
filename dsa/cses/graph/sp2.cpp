#include<bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define int long long
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
 
main()
{
    fast ;
    int n , m,q;
    cin >> n >> m>> q;
    vector<vector<int>> g(n, vector<int>(n, 1e15));
    for(int i=0;i<n;i++)g[i][i]=0;
 
    for(int i=0 ; i<m ; i++ )
    {
        int u , v, w;
        cin >> u >> v >> w;
        --u;--v;
        g[u][v]=min(w,g[u][v]);
        g[v][u]=min(w,g[v][u]);
    }
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(g[i][k]==1e15||g[k][j]==1e15)continue;
        if(g[i][k]+g[k][j]<g[i][j]) g[i][j] = g[i][k]+g[k][j];
    }
    for(int _=0;_<q;_++){
        int i,j;
        cin>>i>>j;
        --i,--j;
        if(g[i][j]==1e15)cout<<-1<<' ';
        else cout<<g[i][j]<<' ';
    }
}