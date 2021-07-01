// an edge, if removed the number of components increases by 1
// Created by skrstv123
#include <bits/stdc++.h>
using namespace std;
#define ar                              array
#define ll                              long long
#define range(i, start, end ,step)      for(ll i=start ;i<end; i += step)
#define rep(i,s,e)                      for(ll i=s;i<=e;++i)
#define reparr(arr)                     for(auto x: arr) cout<<x<<" ";
#define repr(i,e,s)                     for(ll i=e; i>=s; i--)
#define vit                             vector<ll>
#define mid(l,r)                        (l+(r-l)/2)
// #define endl                            '\n'
#define vr                              vector
#define pr                              pair
#define pll                             pair<ll, ll> 
#define pb                              push_back
#define fp                              first
#define sp                              second
#define djpq                            priority_queue< pll , vr<pll>, greater<pll> >

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll in[MAX_N], low[MAX_N];;
bool vis[MAX_N];
vr<vit> graph(MAX_N);
ll timer=0;

void dfs(ll u, ll p){
	vis[u] =1;
	in[u] = low[u] = timer;
	timer++;
	for(ll v: graph[u]){
		if(v==p) continue;
		if(vis[v]) {
			// backward edge
			low[u] = min(low[u], in[v]);
		}
		else{
			// forward edge
			dfs(v, u);
			// if low[child] < in[node] it means the child is connected to an ancestor of node, hence cant form a bridge
			// this needs to be propagated so that other nodes in the chain also look connected to an ancestor
			if(low[v]> in[u]) 
				cout<<u<<" - "<<v<<" is a bridge!"<<endl;

			low[u] = min(low[u], low[v]);
		}
	}
}

void solve() {
	
	ll n,m,x,y;
	cin>>n>>m;
	while(m--){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1, -1);
	
	// 4 4
	// 1 2
	// 2 3
	// 2 4
	// 3 4
	// 1 - 2 is a bridge!

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}
