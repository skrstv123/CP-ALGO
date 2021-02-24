// Created by skrstv123
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define range(i, start, end ,step) for(ll i=start ;i<end; i += step)
#define rep(i,s,e) for(ll i=s;i<=e;++i)
#define reparr(arr) for(auto x: arr) cout<<x<<" ";

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
	ll n;
	cin>>n;
	vector<ll> co(n);
	rep(i, 0, n-1) cin>>co[i];
	set<ll> nums;
	for(auto c: co){
		set<ll> temp;
		for(auto x: nums) temp.insert(x + c);
		for(auto x: temp) nums.insert(x);
		nums.insert(c);
		// reparr(nums); cout<<'\n';
	}
	cout<<nums.size()<<'\n';
	reparr(nums);
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