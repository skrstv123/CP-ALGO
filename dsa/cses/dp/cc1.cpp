#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
	ll n,x;
	cin>>n>>x;
	vector<ll> dp(x+1, 0);
	dp[0] = 1;
	ll coin[n];
	for(int i=0;i<n;i++) cin>>coin[i];
	for(int i=1;i<=x;i++){
		for(auto c: coin){
			if(i-c>=0) (dp[i]+=dp[i-c])%=MOD;
		}
	}
	cout<<dp[x];

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