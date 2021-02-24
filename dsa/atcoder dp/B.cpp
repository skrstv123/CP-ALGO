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

void solve() {
	ll n,k;
	cin>>n>>k;
	vit h(n);
	rep(i, 0, n-1) cin>>h[i];
	vit dp(n, INF);
	dp[0] = 0;
	rep(i, 1, n-1)
		rep(j, 1, k)
			if(i-j>=0) dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
	// reparr(dp);
	cout<<dp[n-1];
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