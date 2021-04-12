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

void dijkstramod(vr<vr<pll>> graph, ll n){
	priority_queue< pair<ll, pll>, vr<pair<ll, pll>>, greater<pair<ll, pll>> > pq;
	vit dist(n, INF); // dist without disc
	vit disc(n, INF); // dist with disc
	dist[0]=0;disc[0]=0;
	pq.push({0, {0,0}}); // {cost, {node, bool(coupon used)}}
	while(!pq.empty()){
		ll d = pq.top().first;
		ll node = pq.top().second.first;
		ll coupused = pq.top().second.second;
		pq.pop();
		if(coupused && disc[node]<d) continue;
		if(!coupused && dist[node]<d) continue;
		for(auto e:graph[node]){
			ll v = e.first, c = e.second;
			if(!coupused){
				if(dist[v]> c+d){ dist[v] = c+d; pq.push({dist[v], {v,0}}); }
				if(disc[v]> c/2 +d){ disc[v] = c/2 +d; pq.push({disc[v], {v,1}}); }
			}
			else{
				if(disc[v]> d + c){
					disc[v] = d+c;
					pq.push({disc[v], {v, 1}});
				}
			}
		}
	}
	// reparr(disc);
	cout<<disc[n-1];
}

void solve() {
	ll n,m;
	cin>>n>>m;
	vr<vr<pll>> graph(n);
	rep(i, 0, m-1){
		ll a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		graph[a].pb({b,c});
	}
	dijkstramod(graph, n);
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