// inout,, for a,b tell if a is in subtree of b
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

//////////////////////////////////////////////////////////////////////////
ll intime[MAX_N], outtime[MAX_N], T=0;
bool vis[MAX_N];
vr<vit> graph(MAX_N);

void itot_dfs(int u){
	vis[u] = 1;
	intime[u] = T++;
	for(auto v: graph[u]){
		if(!vis[v]) itot_dfs(v);
	}
	outtime[u] = T++;
}

//    1
// 2     3
//     4    5

void solve() {
	graph[1].push_back(2); graph[2].push_back(1); 
	graph[1].push_back(3); graph[3].push_back(1); 
	graph[3].push_back(4); graph[4].push_back(3); 
	graph[3].push_back(5); graph[5].push_back(3); 
	itot_dfs(1);
	ll q;
	cin>>q;
	while(q--){
		ll a,b;
		cin>>b>>a;
		// if a (is in subtree of) b, intime(a)<intime(b) and outtime(a)>outtime(b)
		cout<<(intime[a]<intime[b] && outtime[a]> outtime[b])<<endl;
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
