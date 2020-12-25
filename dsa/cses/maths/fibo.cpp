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

std::map<ll, ll> mp;
ll fibo(ll n){
	// We will be using the following recursion-
	// If n is even then k=n2:
	// F(n)=[2×F(k−1)+F(k)]×F(k)
	// If n is odd then k=n+12:
	// F(n)=F(k)×F(k)+F(k−1)×F(k−1)
	if(mp.count(n)) return mp[n];
	if(n==0) return 0;
	if(n==1||n==2) return 1;
	if(n&1){
		ll k=(n+1)>>1;
		ll k1 = fibo(k), k2=fibo(k-1);
		return mp[n] = ((k1*k1)%mod + (k2*k2)%mod)%mod;
	}
	else{
		ll k=n>>1;
		ll k1 = fibo(k), k2=fibo(k-1);
		return mp[n] = 	((((2ll*k2)%mod + k1)%mod)*k1)%mod;
	}
}
main(){
	ll n;
	cin>>n;
	cout<<fibo(n);
}