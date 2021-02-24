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

void level_marker(vit nodes, vit levels, ll i, ll j, ll cl=-1){
	if(j<i || i>j) return;
	if(i==j) { levels[i] = cl+1; return; }
	else{
		ll maxe = -1, maxi = -1; 
		rep(idx, i, j){
			if(nodes[idx]>maxe){
				maxe = nodes[idx];
				maxi = idx;
			}
		}
		levels[maxi] = cl+1;  
		level_marker(nodes, levels, i, maxi-1, cl+1);
		level_marker(nodes, levels, maxi+1, j, cl+1);
	}
}

void solve() {
	ll n;
	cin>>n;
	vit nodes(n);
	rep(i, 0, n-1) cin>>nodes[i];
	vit levels(n,0);
	level_marker(nodes, levels, 0, n-1, -1);
	reparr(levels);
	cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}