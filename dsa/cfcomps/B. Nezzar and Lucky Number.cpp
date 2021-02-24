#include <bits/stdc++.h>
using namespace std;
#define ll long long int   
bool chk(ll x, ll d){
    while(x){
        if(x%10==d)
        return true;
        x/=10;
    }
    return false;
}
main(){
    int t;
    cin>>t;
    while(t--){
        ll q,d;
        cin>>q>>d;
        ll arr[q];
        ll mx=-1;
        for(ll i=0;i<q;i++){
            cin>>arr[i];
        }
        mx= *max_element(arr, arr+q);
        bool dp[mx+1]={false};
        dp[0]=true;
        for(ll y=d;y<=mx;y++){
            if(dp[y-d] || chk(y,d))
            dp[y] = true;
        }
        for(auto p: arr){
            if(dp[p])
            cout<<"YES"<<'\n';
            else
            cout<<"NO"<<'\n';
        }
    }
}