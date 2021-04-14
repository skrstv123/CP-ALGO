// Created by skrstv123
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define range(i, start, end ,step) for(ll i=start ;i<end; i += step)
#define rep(i,s,e) for(ll i=s;i<=e;++i)
#define reparr(arr) for(auto x: arr) cout<<x<<" ";
#define repr(i,e,s) for(ll i=e; i>=s; i--)
#define vit vector<ll>
#define mid(l,r) (l+(r-l)/2)
#define endl '\n'
#define vr vector
#define pr pair
#define pll pair<ll, ll> 
#define pb push_back
#define fp first
#define sp second

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
	ll n,m,a,b;
	cin>>n>>m;
	ll indegree[n+1] = {0};
	vit graph[n+1];
	rep(i,1,m){
		cin>>a>>b;
		graph[a].pb(b);
		indegree[b]++;
	}
	queue<ll> Q;
	////////////////////////////////////////////
	// so that no nodes have extra indegree
	// if they have, they will not be able to contribute to the chains (ans)
	// all nodes contributing extra indegrees are detected and their contri
	// is nullified.
	rep(i, 2, n){
		if(indegree[i]==0) Q.push(i);
	}
	while(!Q.empty()){
		ll u = Q.front();
		Q.pop();
		for(ll v: graph[u]){
			indegree[v]--;
			if(indegree[v]==0) Q.push(v);
		}
	}
	////////////////////////////////////////////
	Q.push(1);
	ll chainspropagated[n+1] = {0};
	chainspropagated[1] = 1;
	// topsort using bfs	
	while(!Q.empty()){
		ll u = Q.front();
		Q.pop();
		for(ll v:graph[u]){
			indegree[v]--;
			(chainspropagated[v]+=chainspropagated[u])%=MOD;
			if(indegree[v]==0) Q.push(v);
		}
	}
	cout<<chainspropagated[n];

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