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
	string s;
	cin>>s;
	ll chmap[26]={0};
	for(char x: s) chmap[ll(x)-97]++;
	ll ans=fact[s.size()];
	for(auto x: chmap) if(x>0) ans=(ans*modinv(fact[x], mod))%mod;
	cout<<ans<<'\n';
}