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

class dsu{
	ll N;
	vit parent;
	vit size;
	public:
		dsu(ll n){
			N = n + 5;
			parent.resize(N);
			size.resize(N);
			rep(i, 0, N-1){
				parent[i]= i;
				size[i] = 1;
			}
		}
		ll find_set(ll v){
			if(v == parent[v]) return v;
			return parent[v] = find_set(parent[v]);
		}
		void union_sets(ll u, ll v){
			u = find_set(u);
			v = find_set(v);
			if(u!=v){
				if(size[u]< size[v])
					swap(u, v);
				parent[v] = u;
				size[u] += size[v];
			}
		}
};

void solve() {
	ll n,m;
	cin>>n>>m;
	vr<vit> edges;
	dsu kkl(n);
	rep(i, 0, m-1){
		ll u,v,w;
		cin>>u>>v>>w;
		edges.push_back({w,u,v});
	}
	sort(edges.begin(),edges.end());
	ll cost = 0;
	for( auto i: edges){
		ll u = i[1], v = i[2];
		ll a = kkl.find_set(u), b = kkl.find_set(v);
		if(a==b){
			continue;
		}else{
			cout<< u <<" "<<v<<endl;
			kkl.union_sets(a,b);
			cost+=i[0];
		}
	}
	cout<< cost;
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
