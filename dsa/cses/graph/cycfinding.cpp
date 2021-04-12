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
const ll nINF = -INF;

void solve() {
	ll n,m,a,b,c,u,v,w,loopnode=-1;
	cin>>n>>m;
	vr<vit> graph_edges;
	rep(i, 0, m-1){
		cin>>a>>b>>c;
		graph_edges.pb({a,b,c});
	}
	vit dist(n+1, 0);
	vit par(n+1, 0);
	dist[1] = 0;
	// bellman ford
	for(ll  _=1;_<n;_++){
		for(auto e: graph_edges){
			u=e[0];
			v=e[1];
			w=e[2];
			if(dist[u]==INF)continue;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				par[v] = u;
			}
			// dist[v]=min(dist[v], dist[u]+w);
			// dist[v]=max(dist[v], nINF);
		}
	}
	// cycle check
	for(auto e: graph_edges){
			u=e[0];
			v=e[1];
			w=e[2];
			if(dist[u]==INF)continue;
			// dist[v]=max(dist[v], nINF);
			if(dist[u]+w<dist[v]){
				loopnode = u;
				break;
			}
		}
	if(loopnode==-1){
		cout<<"NO";
	}else{
		rep(i, 0, n-1) loopnode = par[loopnode];
		vit cycle;
		u= loopnode;
		while(1){
			cycle.push_back(u);
			if(u==loopnode && cycle.size()>1) break;
			u = par[u];
		}
		reverse(cycle.begin(), cycle.end());
		cout<<"YES\n";
		reparr(cycle);
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