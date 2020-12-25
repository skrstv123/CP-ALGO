#include <bits/stdc++.h>
using ll = long long;
#define mod ll(1e9+7)
#define inf ll(4e18+1)
#define vll vector<ll>
using namespace std;


main(){
	ll t,n,_;
	cin>>t;
	while(t--){
		cin>>n;
		ll nim_sum = 0;
		for(ll i=0;i<n;i++){
			cin>>_;
			// if(i&1){ stair game
			// cin>>_; stair game
			// cin>>_, _%=4; nim game II
			nim_sum^=_;
			// } stair game
		}
		cout<<((nim_sum==0)?"second\n":"first\n");
	}
}