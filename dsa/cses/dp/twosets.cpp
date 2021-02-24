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
	ll s = (n*(n+1))>>1;
	if(s&1) {cout<<0; return; }

	vector<vit> dp(2, vit(s+1,0));
	dp[0][0] = 1;
	rep(i, 2, n){
		rep(j, 0, s){
			dp[1][j] = dp[0][j];
			if(j-i>=0) (dp[1][j]+=dp[0][j-i])%=MOD;
		}
		rep(k, 0, s) dp[0][k] = dp[1][k];
	}
	cout<<dp[0][(s>>1)];
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