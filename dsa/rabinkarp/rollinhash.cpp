#include<bits/stdc++.h>
using llt = long long int; 

/* -------------------------RABIN KARP, ROLLING HASH------------------------- */
llt mod=1e9 + 7; 
llt p = 31;
void makehash(std::string s,llt hash[], llt power[]){
    hash[0] = int(s[0])-96;
    power[0]=1;
    for(int i=1; i<s.size();i++) {
    hash[i] = ((p*hash[i-1])%mod + (int(s[i])-96))%mod;
    power[i] = (power[i-1]*p)%mod;
    }
}

llt gethash(llt hash[], llt power[], llt l, llt r){
    if(!l) return hash[r];
    return (hash[r] - hash[l-1]*power[r-l+1]%mod + mod)%mod;
}
/* -------------------------RABIN KARP, ROLLING HASH------------------------- */


int main() {
	// your code goes here
    int t;
    std::cin >> t;
    while(t--){
        std::string s; 
        llt ans=0;
        std::cin >> s;
        llt hash[s.size()+1];
        llt power[s.size()+1];
        makehash(s, hash, power);
        for(int i=2;i<s.size();i+=2){
            int a,b,c,d,e,f,g,h; 
            a = 0;  b=int(i/2)-1;
            c = b+1 ; d = i-1;
            e = i; f=i+int((s.size()-i)/2) - 1;
            g = f+1; h = s.size()-1;
            if(gethash(hash, power, a , b)==gethash(hash,power, c ,d))
            if(gethash(hash,power, e, f)==gethash(hash,power, g, h))
            ans++;
        }
        std::cout << ans << std::endl;
    }
	
	return 0;
}
