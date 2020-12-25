#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
int start, end1;
bool visited[100001];
int par[100001];
vector<vector<int>> graph_adj;

bool dfs_cycle(int u, int p)
{
	visited[u] = true;
	par[u] = p;
	for(int v: graph_adj[u])
	{
		if(visited[v] && v!=p) 
		{
			start = v; 
			end1 = u; 
			return true;
		}
		if(!visited[v]) if(dfs_cycle(v,u)) return true;
	}
	return false;
}

int main(){
    cin>>n>>m;

    graph_adj.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph_adj[a].push_back(b);
        graph_adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs_cycle(i,0)){
                vector<int> ans;
                ans.push_back(end1);
                int en=par[end1];
                while(en!=par[start]){
                    ans.push_back(en);
                    en=par[en];
                }
                ans.push_back(end1);
                
                cout<<ans.size()<<endl;
                for(auto x:ans)cout<<x<<' ';
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";

}
