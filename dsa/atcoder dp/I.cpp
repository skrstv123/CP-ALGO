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
	cout<<fixed;
	cout<<setprecision(10);
	vector<double> c(n);
	rep(i, 0, n-1) cin>>c[i];
	vector<vector<double>>dp(2,vector<double>(n+1, 0.0));
	dp[0][0]=1.0;
	rep(i, 1, n){
		rep(j,0,i){
			if(!j)dp[1][j] = dp[0][j]*(1-c[i-1]);
			else dp[1][j] = dp[0][j]*(1-c[i-1]) + dp[0][j-1]*c[i-1];
		}
		rep(x,0,n){dp[0][x] = dp[1][x]; dp[1][x] = 0.0;}
	}
	ll x = n/2 + 1;
	double ans=0.0;
	rep(i, x,n) ans+=dp[0][i];
	// reparr(dp[0]);
	cout<<ans;
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