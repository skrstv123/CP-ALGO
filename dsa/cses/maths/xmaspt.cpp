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
	// This is a standard problem of finding derangements in a sequence.
	// The recursive formula is D(n)=(D(n−1)+D(n−2))(n−1).
	ll n;
	cin>>n;
	ll mem[n+1];
	mem[1]=0,mem[2]=1;
	for(ll i=3;i<=n;i++) (mem[i] = (mem[i-1]+mem[i-2])*(i-1))%=mod;
	cout<<mem[n];
}