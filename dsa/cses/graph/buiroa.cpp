#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<vector<int>> graph;
bool visited[100001];
void dfs(int s){
    visited[s]=true;
    for(int x: graph[s]){
        if(!visited[x])
        dfs(x);
    }
}

main(){
    vector<int> ans;
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ans.push_back(i);
            dfs(i);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=0;i<ans.size()-1;i++)
    cout<<ans[i]<<' '<<ans[i+1]<<endl;
}