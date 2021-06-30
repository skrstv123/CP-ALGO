// Created by skrstv123
// cycle in graphh using dsu
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
	dsu test(n);
	rep(i, 0, m-1){
		ll u,v;
		cin>>u>>v;
		ll a = test.find_set(u);
		ll b = test.find_set(v);
		if(a==b){
			cout<<"cycle found!";
			return;
		}
		test.union_sets(u,v);
	}
	cout<<"cycle not found!";

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
