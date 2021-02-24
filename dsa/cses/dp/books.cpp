// Created by skrstv123
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define repl(i,n) for(ll i=0;i<n;++i)
#define repe(i,n) for(ll i=0;i<=n;++i)
#define reparr(arr) for(auto x: arr) cout<<x<<" ";

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
	ll n,x;
	cin>>n>>x;
	// cout<<"xxxxxxxxxxx\n";
	vector<ll> pr(n,0);
	vector<ll> pa(n,0);
	// cout<<"xxxxxxxxxxx\n";
	vector<vector<ll>> dp(2, vector<ll>(x+1,0));
	repl(i,n) cin>>pr[i];
	repl(i,n) cin>>pa[i];

	repl(i,n){
		for(ll j=0;j<=x;j++){
			if(j<pr[i]) dp[1][j] = dp[0][j];
			else dp[1][j] = max(dp[0][j], dp[0][j-pr[i]] + pa[i]);
		}
		for(ll _=0;_<=x;_++) dp[0][_]= dp[1][_];
	}
	cout<<dp[0][x];
	
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