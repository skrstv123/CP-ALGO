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
	ll n,w;
	cin>>n>>w;
	vector<vit> itm(n, vit(2));
	rep(i,0,n-1) cin>>itm[i][0]>>itm[i][1]; //w,v
	vector<vit> dp(2, vit(w+1,0));
	rep(j, 0, n-1){
		rep(i, 1, w){
			dp[1][i] = dp[0][i]; 
			if(i>=itm[j][0])
				dp[1][i] = max( dp[1][i], 
					itm[j][1] + dp[0][i-itm[j][0]] );
		}
		rep(x,0,w) dp[0][x] = dp[1][x];
	}
	cout<<dp[0][w];
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