#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool teams[100001];
bool visited[100001];
vector<vector<int>> graph_adj;

bool bfs_bipartite(int src){
    queue<int> q;
    q.push(src);visited[src]=true;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int x: graph_adj[v]){
            if(x==v) return false;
            if(!visited[x]){
                visited[x]=true;teams[x]=!teams[v];
                q.push(x);
            }
            else if(teams[x]==teams[v]) return false;
        }
    }
    return true;
}

main(){
    int n,m,count=0;
    cin>>n>>m;

    graph_adj.resize(n+1);
    bool ans;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph_adj[a].push_back(b);
        graph_adj[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){ans=bfs_bipartite(i);
            if(!ans)break;
        }
    }
    
    if(ans)for(int i=1;i<=n;i++)cout<<teams[i]+1<<' ';
    else cout<<"IMPOSSIBLE";
}

