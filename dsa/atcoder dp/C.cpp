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
	ll n;
	cin>>n;
	vector<vit> acts(n, vit(3));
	rep(i,0,n-1){
		cin>>acts[i][0]>>acts[i][1]>>acts[i][2];
	} 
	vector<vit> dp(n, vit(3));
	rep(i,0,2) dp[0][i] = acts[0][i];
	rep(i, 1, n-1){
		dp[i][0] = max(acts[i][0] + dp[i-1][1], acts[i][0] + dp[i-1][2]);
		dp[i][1] = max(acts[i][1] + dp[i-1][0], acts[i][1] + dp[i-1][2]);
		dp[i][2] = max(acts[i][2] + dp[i-1][0], acts[i][2] + dp[i-1][1]);
	}
	cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
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