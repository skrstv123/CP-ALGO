#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<vector<pair<int,int>>> path;
vector<vector<bool>> vis;
int sx, sy, ex, ey;
vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};
map<pair<int, int>, char> mvl;


void bfs()
{
	queue<pair<int,int>> q;
	q.push({sx,sy});
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(auto mv: moves)
		{
			int mvx = mv.first;
			int mvy = mv.second;

            int nx,ny;
            nx=cx+mvx;
            ny=cy+mvy;

            if(nx<0 || nx==n || ny<0 || ny==m)continue;

			if(!vis[nx][ny])
			{
				q.push({nx, ny});
				vis[nx][ny] = true;
				path[nx][ny] = {mvx,mvy};
			}
		}
	}
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mvl[{-1,0}] = 'U';
	mvl[{1,0}] = 'D';
	mvl[{0,-1}] = 'L';
	mvl[{0,1}] = 'R';

	cin >> n >> m;

	path.resize(n);
	vis.resize(n);

	for(int i = 0; i < n; ++i)
	{
		path[i].resize(m);
		vis[i].resize(m);
	}

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
		{
			path[i][j] = {-1,-1};
			char c; cin >> c;
			if(c == '#') vis[i][j] = true;
			if(c == 'A'){ sx = i; sy = j;}
			if(c == 'B'){ ex = i; ey = j;}
		}

	bfs();

	if(!vis[ex][ey])
	{
		cout << "NO" << endl;
	}
    else{
		cout << "YES" << endl;

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
    }
    return 0;
}