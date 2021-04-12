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

stack<ll> st;
bool vis2[100005] = {false};
bool stfl[100005] = {false};
vr<vit> graph(100005);
bool dfs(ll cur){
	vis2[cur] = true;
	st.push(cur);
	stfl[cur] = true;
	for(ll next: graph[cur]){
		if(!vis2[next])
			if(dfs(next)) return true;
		if(stfl[next]){
			st.push(next);
			return true;
		}
	}
	st.pop();
	stfl[cur] = false;
	return false;
}

stack<ll> stck;
bool vis[100005];

void topo(ll node){
	vis[node] = true;
	for(auto e: graph[node]){
		if(!vis[e]) topo(e);
	}
	stck.push(node);
}

void solve() {
	ll n,m,a,b;
	cin>>n>>m;
	rep(i,0,m-1){
		cin>>a>>b;
		graph[a].pb(b);
	}

	bool ans = false;
	rep(i,1,n){
		if(!vis2[i]) ans|=dfs(i);
	}
	if(ans){ cout<<"IMPOSSIBLE"; return;}

	rep(i,1,n){if(!vis[i])topo(i);}
	while(!stck.empty()){
		cout<<stck.top()<<' ';
		stck.pop();
	}
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