#include <bits/stdc++.h>
using ll = long long;
#define mod ll(1e9+7)
#define vll vector<ll>
using namespace std;
ll modex(ll a,ll b, ll m){
	ll r=1;
	while(b){
		if(b&1)
			r=(r*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return r;
}
ll modinv(ll a,ll m){
	return modex(a, m-2, m);
}
vector<vll> matmul(vector<vll> u, vector<vll> v, ll n){
	vector<vll> r(n, vll(n,0));
	for (ll i = 0; i < n; ++i)for(ll j=0;j<n;j++)for(ll k=0;k<n;k++) 
		r[i][j] = (r[i][j] + (u[i][k]*v[k][j])%mod)%mod;
	return r;	
}
vector<vll> bmex(vector<vll> m, ll n, ll e){
	vector<vll> r(n, vll(n,0));
	for(ll i=0;i<n;i++) r[i][i] = 1;
	while(e){
		if(e&1) r=matmul(r, m, n);
		e>>=1;
		m = matmul(m, m, n);
	}
	return r;
}

main(){
	ll n,m,k;
	cin>>n>>m>>k;
	vector<vll> mt(n, vll(n,0));
	while(m--){
		ll a,b;
		cin>>a>>b, a--, b--;
		mt[a][b]++;
	}
	cout<<bmex(mt, n, k)[0][n-1];
}