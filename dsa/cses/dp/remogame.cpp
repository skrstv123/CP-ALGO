// Created by skrstv123
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define range(i, start, end ,step) for(ll i=start ;i<end; i += step)
#define rep(i,s,e) for(ll i=s;i<=e;++i)
#define reparr(arr) for(auto x: arr) cout<<x<<" ";
#define vit vector<ll>

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
	ll n;
	cin>>n;
	vit v(n);
	rep(i, 0, n-1) cin>>v[i];
	vector<vit> dp(n, vit(n, 0));
	rep(len, 1, n){
		for(ll i=0; i+len<=n; i++){
			ll j=i+len-1;
			ll a,b,c;
			a = (i+2<=j) ? dp[i+2][j]: 0;
			b = (i+1<=j-1) ? dp[i+1][j-1]: 0;
			c = (i<=j-2) ? dp[i][j-2] : 0;
			dp[i][j] = max(v[i] + min(a,b), v[j] + min(b,c));
		}
	}
	cout<<dp[0][n-1];
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