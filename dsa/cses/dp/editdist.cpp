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
	string a,b;
	cin>>a>>b;
	ll la,lb;
	la=a.length(), lb=b.length();
	vector<vector<ll>> dp(la+1, vector<ll>(lb+1, 0));
	rep(i, 0, la){
		rep(j, 0, lb){
			if(i==0) dp[i][j] = j;
			else if(j==0) dp[i][j] = i;
			else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
			else{
				dp[i][j] = 1 + min(
					dp[i][j-1], //insert
					min(dp[i-1][j], //remove
						dp[i-1][j-1] //replace
					)
				);
			}
		}
	}
	cout<<dp[la][lb];
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