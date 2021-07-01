// answer in o(1) the size of subtrees of any node of tree( subtree size of leaf is 1 )
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
/////////////////////////////////////////////////////////////////////////////
ll size[MAX_N];
bool vis[MAX_N];
vr<vit> graph(MAX_N);

ll dfs_sizePreProcess(int u){
	vis[u]=1;
	ll cur = 1;
	for(auto v: graph[u]){
		if(!vis[v]) cur += dfs_sizePreProcess(v);
	}
	size[u] = cur;
	return cur;
}

//    1
// 2     3
//     4    5

void solve() {
	graph[1].push_back(2); graph[2].push_back(1); 
	graph[1].push_back(3); graph[3].push_back(1); 
	graph[3].push_back(4); graph[4].push_back(3); 
	graph[3].push_back(5); graph[5].push_back(3); 
	dfs_sizePreProcess(1);
	ll q;
	cin>>q;
	while(q--){
		ll a;
		cin>>a;
		cout<<size[a]<<endl;
	}
	
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
