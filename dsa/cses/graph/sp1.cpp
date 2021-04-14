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
vector<int> dist(nax , inf );
 
void dijkstra()
{
    priority_queue< pii , vector<pii> , greater<pii >> Q;
    dist[ 1 ] = 0;
    Q.push( {0,1} );
 
    while( !Q.empty() )
    {
        pii p = Q.top();
        Q.pop();
        if(dist[p.ss]<p.ff) continue;
        for(auto i : g[p.ss] )
        {
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