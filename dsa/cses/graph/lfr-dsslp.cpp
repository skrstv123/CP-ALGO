// Created by skrstv123
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define range(i, start, end ,step) for(ll i=start ;i<end; i += step)
#define rep(i,s,e) for(ll i=s;i<=e;++i)
#define reparr(arr) for(auto x: arr) cout<<x<<" ";
#define repr(i,e,s) for(ll i=e; i>=s; i--)
#define vit vector<ll>
#define mid(l,r) (l+(r-l)/2)
#define endl '\n'
#define vr vector
#define pr pair
#define pll pair<ll, ll> 
#define pb push_back
#define fp first
#define sp second
 
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
 
vr< vr<pll> > graph(MAX_N);
vit dist(MAX_N, INF);
vit par(MAX_N, -1);
ll n,m,a,b;
 
void dsslp(ll node){
	priority_queue< pll, vr<pll>, greater<pll> > Q;
	Q.push({-1, 1});
	while(!Q.empty()){
		ll d = Q.top().fp;
		ll u = Q.top().sp;
		Q.pop();
		if(dist[u]<d) continue;
		for(pll v: graph[u]){
			if(dist[v.fp]> d + v.sp){
				par[v.fp] = u ;
				dist[v.fp] = d + v.sp;
				Q.push({dist[v.fp], v.fp});
			}
		}
	}
}
 
void solve() {
	cin>>n>>m;
	// graph.resize(n+1);
	// dist.resize(n+1);
	// par.resize(n+1);
	rep(i,0,m-1){
		cin>>a>>b;
		graph[a].pb({b,-1});
	}
	dsslp(1);
	// reparr(par);
	dist[1] = -1;
	if(dist[n]==INF) cout<<"IMPOSSIBLE";
	else{
		ll x=n;
		vit ans;
		while(x!=-1){
			ans.pb(x);
			x = par[x];
		}
		// reverse(ans.begin(), ans.end());
		cout<<ans.size()<<'\n';
		// reparr(ans);
		repr(i, ans.size()-1, 0) cout<<ans[i]<<' ';
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