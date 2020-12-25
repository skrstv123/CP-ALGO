#include <bits/stdc++.h>
using ll = long long;
#define mod ll(1e9+7)
#define inf ll(4e18+1)
#define vll vector<ll>
using namespace std;


main(){
	ll n,k;
	cin>>n>>k;
	ll p[k];
	for(ll i=0;i<k;i++) cin>>p[i];
	bool dp[n+1]={false};
	for(ll i=1;i<=n;i++)for(ll j=0;j<k;j++) if(i>=p[j] && !dp[i-p[j]]) dp[i] = true;
	for(ll i=1;i<=n;i++) cout<<(dp[i]?"W":"L");
}