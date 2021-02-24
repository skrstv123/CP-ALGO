#include <bits/stdc++.h>
using namespace std;
int ci(char x){
    return x-'0';
}
main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string ans= "1";
        if(n>1){
            for(int i=1;i<n;i++){
                
                if((ci(s[i-1])+ ci(ans[i-1]))!=(ci(s[i]) + 1))
                    ans+="1";
                else ans+="0";
            }
        }
        cout<<ans<<'\n';
    }
}