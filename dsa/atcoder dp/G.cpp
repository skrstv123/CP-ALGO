// Created by skrstv123
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define range(i, start, end ,step) for(ll i=start ;i<end; i += step)
#define rep(i,s,e) for(ll i=s;i<=e;++i)
#define reparr(arr) for(auto x: arr) cout<<x<<" ";
#define vit vector<ll>
#define mid(l,r) (l+(r-l)/2)
#define endl '\n'

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void dfs(ll i, vit graph[], ll dp[], bool vis[]){
	vis[i] = true;
	for(auto x:graph[i]){
		if(!vis[x]) dfs(x, graph, dp, vis);
		dp[i] = max(dp[i], 1 + dp[x]);
	}
}

void solve() {
	ll n,e;
	cin>>n>>e;
	vit graph[n+1];
	rep(i, 1,e) {
		ll a,b;
		cin>>a>>b;
		graph[a].push_back(b);
	}
	ll dp[n+1] = {0};
	bool vis[n+1] = {false};
	rep(i, 1, n) if(!vis[i]) dfs(i, graph, dp, vis);
	ll mx=-1;
	rep(i, 1, n) mx=max(mx, dp[i]);
	cout<<mx;
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