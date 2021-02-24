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

void solve(){
	ll h,w;
	cin>>h>>w;
	vector<vector<char>> grid(h, vector<char>(w));
	rep(i,1,h) rep(j, 1, w) cin>>grid[i-1][j-1];
	vector<vit> dp(h, vit(w, 0));
	dp[0][0]=1;
	rep(i, 0, h-1)
		rep(j, 0, w-1)
			if(grid[i][j]=='.'){
				if(i-1>=0) (dp[i][j]+=dp[i-1][j])%=MOD;
				if(j-1>=0) (dp[i][j]+=dp[i][j-1])%=MOD;
			}
	cout<<dp[h-1][w-1];
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