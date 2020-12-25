#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define llt long long int
#define INF (llt)1e15
#define nINF -1*INF

// finding sssp using bf when weights are mul by -1 gives sslp 

vector<vector<llt > > edges;
vector<llt > dist;

void sssp_dp(llt  n){
	// bellman ford
	for(llt  _=1;_<n;_++){
		for(auto e: edges){
			llt  u=e[0];
			llt  v=e[1];
			llt  w=e[2];
			if(dist[u]==INF)continue;
			dist[v]=min(dist[v], dist[u]+w);
			dist[v]=max(dist[v], nINF);
		}
	}
	// cycle check
	for(llt  _=1;_<n;_++){
		for(auto e: edges){
			llt  u=e[0];
			llt  v=e[1];
			llt  w=e[2];
			if(dist[u]==INF)continue;
			dist[v]=max(dist[v], nINF);
			if(dist[u]+w<dist[v]) dist[v]=-INF;
		}
	}
}

main()
{
	fastio;
	llt  n,m;
	cin>>n>>m;
	dist.resize(n+1);
	for(llt  _=0;_<=n;_++)dist[_]=INF;
	dist[1]=0;
	while(m--){
		llt  a,b,c;
		cin>>a>>b>>c;
		edges.push_back({a,b,-c}); // c*-1
	}
	sssp_dp(n);
	if(dist[n]==nINF)cout<<-1;
	else cout<<dist[n]*-1;


}