#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

/*
#1  ACCEPTED	0.01 s	details
#2	ACCEPTED	0.01 s	details
#3	ACCEPTED	0.01 s	details
#4	ACCEPTED	0.01 s	details
#5	ACCEPTED	0.01 s	details
#6	ACCEPTED	0.17 s	details
#7	ACCEPTED	0.17 s	details
#8	ACCEPTED	0.17 s	details
#9	ACCEPTED	0.17 s	details
#10	ACCEPTED	0.17 s	details
#11	ACCEPTED	0.01 s	details
#12	ACCEPTED	0.11 s  details
*/

vector<vector<int>> graph;
bool vis[200001];
vector<int> par;


void bfs(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int cs=q.front();
        q.pop();
        for(int x: graph[cs]){
            if(!vis[x]){
                q.push(x);
                vis[x]=true;
                par[x]=cs;
            }
        }
    }
}

main(){
    int n,m;
    cin>>n>>m;
    par.resize(n+1);
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vis[1]=true;
    bfs(1);
    
    if(!vis[n])
    cout<<"IMPOSSIBLE";
    else{
        vector<int> path;
        for(int curr=n;curr!=0;curr=par[curr])
            path.push_back(curr);
        reverse(path.begin(), path.end());
        cout<<path.size()<<endl;
        for(auto x:path)cout<<x<<' ';
    }
}