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
	ll fact[1000001];
	fact[0]=fact[1]=1;
	for(ll i=2;i<1000001;i++)
		fact[i]=(i*fact[i-1])%mod;
	ll n;
	cin>>n;
	for (ll i = 0; i < n; ++i)
	{
		/* code */
		ll a,b,ans;
		cin>>a>>b;
// 		cout<<fact[a]<<' '<<modinv(fact[b], mod)<<' '<<modinv(fact[a-b], mod)<<'\n';
		ans=(fact[a]*modinv(fact[b], mod))%mod;
		ans*=modinv(fact[a-b], mod);
		ans%=mod;
		cout<<ans<<'\n';
	}
}