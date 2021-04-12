#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mmax 1001
int n, m, sx,sy;
vector<vector<pair<int,int>>> path(mmax, vector<pair<int,int>>(mmax, {-1, -1}));
bool vis[mmax][mmax] = {false};
bool vis2[mmax][mmax] = {false};
// vector<vector<bool>> vis2(mmax, vector<bool>(mmax, false));
vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int timeM[mmax][mmax];
map<pair<int, int>, char> mvl;


main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
    mvl.reserve(9000);
    mvl[{-1,0}] = 'U';
    mvl[{1,0}] = 'D';
    mvl[{0,-1}] = 'L';
    mvl[{0,1}] = 'R';
	// path.resize(n);vis.resize(n);timeM.resize(n);vis2.resize(n);
 //    for(int i=0;i<n;i++) { path[i].resize(m); vis[i].resize(m); timeM[i].resize(m); vis2[i].resize(m);}
    queue<vector<int>> q;
    char c;
    for (int i = 0; i < n; ++i) for(int j = 0; j < m; ++j)
		{
		    cin >> c;
			if(c == '#') {vis[i][j] = true; vis2[i][j] = true;}
			if(c == 'A') {sx = i; sy = j;}
            if(c=='M') q.push({i,j,0});
	    }

    while(!q.empty()){
        auto u = q.front(); 
        q.pop();
        timeM[u[0]][u[1]]=(timeM[u[0]][u[1]]>0)?min(u[2], timeM[u[0]][u[1]]):u[2];
        //  timeM[u[0]][u[1]]=u[2];
        vis[u[0]][u[1]] = true;
        for(auto dxdy: moves){
            int x=u[0],y=u[1];
            x+=dxdy.first; y+=dxdy.second;
            if(x<0 || x>=n || y<0 || y>=m) continue;
            if(!vis[x][y])
            q.push({x,y,u[2]+1});
        }
    }

//     for (int i = 0; i < n; ++i){
//         for(int j = 0; j < m; ++j)
// 		cout<<timeM[i][j]<<" ";
//         cout<<endl;
//     } 
    bool ans=false;
    int ex,ey;
    q.push({sx,sy,0});
    while(!q.empty()){
        auto u = q.front(); 
        q.pop();
        vis2[u[0]][u[1]] = true;
        
        if(u[2]>=timeM[u[0]][u[1]] && vis[u[0]][u[1]]) continue;
        vis[u[0]][u[1]] = true;
        if(u[0]==0 || u[0]==n-1 || u[1]==0 || u[1]==m-1) {
            ans=true;
            ex=u[0];ey=u[1];
            break;
        }
        for(auto dxdy: moves){
            int x=u[0],y=u[1];
            x+=dxdy.first; y+=dxdy.second;
            if(x<0 || x>=n || y<0 || y>=m) continue;
            if(!vis2[x][y]){ q.push({x,y,u[2]+1}); path[x][y]=dxdy; }
        }
    }
    if(ans){
        cout<<"YES"<<endl;

        vector<char> ans;
        pair<int,int> end = {ex,ey};
        
        while(!(end.first==sx && end.second==sy))
        {
            pair<int, int> lm = path[end.first][end.second];
            ans.push_back(mvl[lm]);
            end.first -= lm.first;
            end.second -= lm.second;    
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto c:ans)
            cout<<c;

        // vector<pair<int,int>> ans;
        // while(!(ex==sx && ey==sy))
        // {
        //     ans.push_back(path[ex][ey]);
        //     ex -= ans.back().first;
        //     ey -= ans.back().second;	
        // }
        // reverse(ans.begin(), ans.end());
        // cout << ans.size() << endl;
        // for(auto c: ans)
        //         if(c.first == 1 and c.second ==0) cout << 'D';
        //         else if(c.first == -1 and c.second ==0) cout << 'U';
        //         else if(c.first == 0 and c.second == 1) cout << 'R';
        //         else if(c.first == 0 and c.second == -1) cout << 'L';

    } else cout<<"NO";
}