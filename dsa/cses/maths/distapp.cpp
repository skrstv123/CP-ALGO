#include <bits/stdc++.h>
using ll = long long;
#define mod ll(1e9+7)
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
main(){
	ll fact[2000001];
	fact[0]=fact[1]=1;
	for(ll i=2;i<2000001;i++)
		fact[i]=(i*fact[i-1])%mod;
	ll m,n;
	cin>>n>>m;
	// (n+k-1)! / (n-1)!*k!.
	ll ans = (fact[n+m-1] * modinv(fact[n-1],mod))%mod ;
	(ans*=modinv(fact[m],mod))%=mod;
	cout<<ans<<'\n';
}