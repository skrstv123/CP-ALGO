// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// # define INF 0x3f3f3f3f 
  
// typedef pair<long long , long long > iPair; 
   
// void shortestPath(vector<pair<long long ,long long > > adj[], long long V, long long src) 
// { 
//     priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

//     vector<bool> vis(V, false);
 
//     vector<long long > dist(V, INF); 
//     pq.push({0, src}); 
//     dist[src] = 0; 
//     while (!pq.empty()) 
//     { 
//         pair<long long  , long long >  u = pq.top(); 
//         pq.pop(); 
//         if(u.first> dist[u.second]) continue;
//         if(vis[u.second]) continue;
//         vis[u.second]=true;
 
//         for (auto x : adj[u.second]) 
//         {   
//             long long v = x.first; 
//             long long weight = x.second; 
//             if(vis[v]) continue;
//             if (dist[v] > u.first + weight) 
//             { 
//                 dist[v] = u.first + weight; 
//                 pq.push({dist[v], v}); 
//             } 
//         } 
//     } 
  
//     // Prlong long shortest distances stored in dist[]
//     for (long long i = 0; i < V; ++i) 
//         printf("%lld ",dist[i]); 
// } 
 
// main() 
// { 
//     long long n,m;
//     cin>>n>>m;
//     vector<iPair> adj[n];
//     for(long long _=0;_<m;_++){
//         long long a,b,c;
//         cin>>a>>b>>c;
//         --a;--b;
//         adj[a].push_back(make_pair(b,c));
//         // adj[b].push_back(make_pair(a,c));
//     }
//     shortestPath(adj, n, 0); 
// } 

 
#include<bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define int long long
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
 
const int nax = 1e5+5;
const int inf = 1e15;
vector<pii> g[nax] ;
vector<int> dist(nax , inf ) , vis(nax, 0);
 
void dijkstra()
{
    priority_queue< pii , vector<pii> , greater<pii >> Q;
    dist[ 1 ] = 0;
    Q.push( {0,1} );
 
    while( !Q.empty() )
    {
        pii p = Q.top();
        Q.pop();
        if( vis[p.ss] ) continue;
 
        vis[ p.ss ] = 1;
        for(auto i : g[p.ss] )
        {
            if(vis[i.ff]) continue;
 
            if( dist[i.ff] > p.ff + i.ss )
            {
                dist[i.ff] = p.ff + i.ss;
                Q.push( { dist[i.ff] , i.ff } );
            }
            
        }
    }
}
 
main()
{
    fast ;
    int n , m;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++ )
    {
        int u , v, w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
    }
    dijkstra();
    for(int i = 1 ; i<= n ; i++ )
        cout << dist[i] << " " ;
}