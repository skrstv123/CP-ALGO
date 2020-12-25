#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m, sx,sy;
vector<vector<pair<int,int>>> path;
vector<vector<bool>> vis;
vector<vector<bool>> vis2;
vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};
vector<vector<int>> timeM;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	path.resize(n);vis.resize(n);timeM.resize(n);vis2.resize(n);
    for(int i=0;i<n;i++) { path[i].resize(m); vis[i].resize(m); timeM[i].resize(m); vis2[i].resize(m);}
    queue<vector<int>> q;
    for (int i = 0; i < n; ++i) for(int j = 0; j < m; ++j)
		{
			path[i][j] = {-1,-1};
			char c; cin >> c;
			if(c == '#') {vis[i][j] = true; vis2[i][j]=true;}
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
        vector<pair<int,int>> ans;
        while(!(ex==sx && ey==sy))
        {
            ans.push_back(path[ex][ey]);
            ex -= ans.back().first;
            ey -= ans.back().second;	
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto c: ans)
                if(c.first == 1 and c.second ==0) cout << 'D';
                else if(c.first == -1 and c.second ==0) cout << 'U';
                else if(c.first == 0 and c.second == 1) cout << 'R';
                else if(c.first == 0 and c.second == -1) cout << 'L';

    } else cout<<"NO";
}