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
#define endl                            '\n'
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

void solve() {
	ll n,m,a,b,c;
	cin>>n>>m;
	vr<vr<pll>> graph(n+1);
	rep(i,1,m){
		cin>>a>>b>>c;
		graph[a].pb({b,c});
	}
	vit dist(n+1, INF);
	vit routes(n+1, 0);
	vit min_nodes(n+1, INF);
	vit max_nodes(n+1, -INF);

	dist[1] = 0;
	routes[1] = 1;
	min_nodes[1]=0;
	max_nodes[1]=0;

	djpq pq;
	pq.push({0,1});
	while(!pq.empty()){
		ll d = pq.top().fp;
		ll u = pq.top().sp;
		pq.pop();
		if(dist[u] < d) continue;
		for(pll e: graph[u]){
			ll v = e.fp;
			ll c = e.sp;
			if(dist[v] < c+d) continue;
			if(c+d == dist[v]){
				(routes[v]+=routes[u])%=MOD;
				min_nodes[v] = min(min_nodes[u] + 1,  min_nodes[v]);
				max_nodes[v] = max(max_nodes[u] + 1, max_nodes[v]);
			}
			else if(c+d< dist[v]){
				dist[v] = c+d;
				routes[v] = routes[u];
				min_nodes[v] = min_nodes[u]+1;
				max_nodes[v] = max_nodes[u] + 1;
				pq.push({dist[v], v});
			}
		}
	}
	cout<<dist[n]<<' '<<routes[n]<<' '<<min_nodes[n]<<' '<<max_nodes[n];

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