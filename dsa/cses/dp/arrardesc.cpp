// Created by skrstv123
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define range(i, start, end ,step) for(ll i=start ;i<end; i += step)
#define rep(i,s,e) for(ll i=s;i<=e;++i)
#define reparr(arr) for(auto x: arr) cout<<x<<" ";

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
	ll n,m;
	cin>>n>>m;
	vector<ll> arr(n);
	range(i, 0, n, 1) cin>>arr[i];
	vector<vector<ll>> dp(n, vector<ll>(m+1, 0));
	rep(i, 0, n-1){
		if(i==0){
			if(arr[i]!=0) dp[i][arr[i]] = 1;
			else rep(j, 1, m) dp[i][j] = 1;
		}
		else if(arr[i]!=0){
			(dp[i][arr[i]] += dp[i-1][arr[i]-1])%=MOD;
			(dp[i][arr[i]] += dp[i-1][arr[i]])%=MOD;
			if(arr[i]<m) (dp[i][arr[i]] += dp[i-1][arr[i]+1])%=MOD;
		}
		else{
			rep(j, 1, m){
				(dp[i][j] += dp[i-1][j-1])%=MOD;
				(dp[i][j] += dp[i-1][j])%=MOD;
				if(j<m)(dp[i][j] += dp[i-1][j+1])%=MOD;
			}
		}
	}
	if(arr[n-1]!=0)
		cout<<dp[n-1][arr[n-1]];
	else{
		ll ans=0;
		rep(i,1,m) (ans+=dp[n-1][i])%=MOD;
		cout<<ans;
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