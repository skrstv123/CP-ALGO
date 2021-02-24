#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
	ll n;
	cin>>n;
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	vector<string> grid(n);
	for(int i=0;i<n;i++){
		cin>>grid[i];
	}
	if(grid[0][0]=='.')
	dp[0][0] = 1;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j] == '.'){
				if(i>0) (dp[i][j] += dp[i-1][j])%=MOD;
				if(j>0) (dp[i][j] += dp[i][j-1])%=MOD;
			}
		}
	}
	cout<<dp[n-1][n-1];
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