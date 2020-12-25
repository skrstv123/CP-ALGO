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

ll dice(n){
	
}

main(){
	ll n;
	cin>>n;
	cout<<dice(n);
}