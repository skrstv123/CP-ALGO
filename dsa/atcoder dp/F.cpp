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
	string s,t;
	cin>>s>>t;
	vector<vit> dp(s.size()+1, vit(1+t.size()));
	rep(i, 0, s.size()){
		rep(j, 0, t.size()){
			if(!i || !j) dp[i][j] = 0;
			else if(s[i-1]==t[j-1]) dp[i][j] =  1+ dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	string ans="";
	ll m=s.size(),n=t.size();
	while(m>0 && n>0){
		if(s[m-1]==t[n-1]) {
			ans = s[m-1]+ans;
			m--,n--;
		}
		else if(dp[m-1][n]>dp[m][n-1]) m--;
		else n--;
	}
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