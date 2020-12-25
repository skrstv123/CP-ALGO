#include <bits/stdc++.h>
using ll = long long;
#define mod ll(1e9+7)
#define inf ll(4e18+1)
#define vll vector<ll>
using namespace std;

vector<vll> matmul(vector<vll> u, vector<vll> v, ll n){
	vector<vll> r(n, vll(n,inf)); // taking min
	for (ll i = 0; i < n; ++i)for(ll j=0;j<n;j++)for(ll k=0;k<n;k++) 
		r[i][j] = min(r[i][j] ,u[i][k] + v[k][j]); 
	return r;	
}
vector<vll> bmex(vector<vll> m, ll n, ll e){
	vector<vll> r(n, vll(n,inf));
	for(ll i=0;i<n;i++)for(ll j=0;j<n;j++) r[i][j] = m[i][j];
	e--;
	while(e){
		if(e&1) r=matmul(m, r, n);
		e>>=1;
		m = matmul(m, m, n);
	}
	return r;
}

main(){
	ll n,m,k;
	cin>>n>>m>>k;
	vector<vll> mt(n, vll(n,inf));
	while(m--){
		ll a,b,c;
		cin>>a>>b>>c, a--, b--;
		mt[a][b]=min(mt[a][b],c);
	}
	vector<vll> aa = bmex(mt, n, k);
	ll ans = aa[0][n-1];
	if(ans==inf) ans=-1;
	// for(ll i=0;i<n;i++){for(ll j=0;j<n;j++) cout<<aa[i][j]<<' '; cout<<'\n';}
	cout<<ans;
}