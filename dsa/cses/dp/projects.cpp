// Created by skrstv123
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define range(i, start, end ,step) for(ll i=start ;i<end; i += step)
#define rep(i,s,e) for(ll i=s;i<=e;++i)
#define reparr(arr) for(auto x: arr) cout<<x<<" ";
#define vit vector<ll>
#define mid(l,r) (l+(r-l)/2)

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

struct job
{
	ll s,f,p;
};
bool cmp(job a, job b){
	return a.f<b.f;
}

ll bs(struct job jobs[], ll i){
	ll l=0, r=i-1;
	while(l<=r){
		ll m = mid(l,r);
		if(jobs[m].f<jobs[i].s){
			if(jobs[m+1].f<jobs[i].s){ l=m+1; }
			else {return m;}
		}
		else{ r = m-1; }
	}
	return -1;
}

void solve() {
	ll n;
	cin>>n;
	struct job jobs[n];
	rep(i, 0, n-1) cin>>jobs[i].s>>jobs[i].f>>jobs[i].p;
	sort(jobs, jobs+n,cmp);
	// rep(i, 0,n-1) cout<<jobs[i].s<<' '<<jobs[i].f<<' '<<jobs[i].p<<'\n';
	vit dp(n, 0);
	dp[0] = jobs[0].p;
	rep(i, 1, n-1){
		ll onlycurr = jobs[i].p;
		ll joblti = bs(jobs, i);
		if(joblti!=-1) onlycurr+=dp[joblti];
		dp[i] = max(dp[i-1],onlycurr);
	}
	cout<<dp[n-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}