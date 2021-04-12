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

void solve() {
	ll n,m,k,a,b,c;
	cin>>n>>m>>k;
	vr<vr<pll>> graph(n+1);
	rep(i, 0, m-1){
		cin>>a>>b>>c;
		graph[a].pb({b,c});
	}
	priority_queue<pll, vr<pll>, greater<pll>> Q;
	Q.push({0,1});
	vit cnt(n+1,0);
	vit ans;
	while(!Q.empty()){
		auto e = Q.top();
		Q.pop();
		cnt[e.sp]++;
		if(cnt[e.sp]>k) continue;
		if(e.sp==n){
			ans.pb(e.fp);
			if(ans.size()==k) break;
		}
		for(auto x: graph[e.sp]){
			if(cnt[x.fp]<k){
				Q.push({e.fp + x.sp, x.fp});
			}
		}
	}
	sort(ans.begin(), ans.end());
	reparr(ans);

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