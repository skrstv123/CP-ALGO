// 139 segmentation fault

#include <bits/stdc++.h>
using namespace std;

bool mark[1000][1000];
char char_map[1000][1000];
vector<vector<pair<int,int>>> path;

void dffs(int x, int y, int m, int n, int p, int q){
    if(char_map[x][y]=='B') return;
    mark[x][y]=true;
    path[x][y]={p,q};

    if(y>0)
    if((char_map[x][y-1]=='.' || char_map[x][y-1]=='B') && mark[x][y-1]==false)dffs(x,y-1,m,n,0,-1);
    
    if(y+1<n)
    if((char_map[x][y+1]=='.' || char_map[x][y+1]=='B') && mark[x][y+1]==false)dffs(x,y+1,m,n,0,1);
    
    if(x>0)
    if((char_map[x-1][y]=='.' || char_map[x-1][y]=='B') && mark[x-1][y]==false)dffs(x-1,y,m,n,-1,0);
    
    if(x+1<m)
    if((char_map[x+1][y]=='.' || char_map[x+1][y]=='B') && mark[x+1][y]==false)dffs(x+1,y,m,n,1,0);
}

int main()
{
    int n,m;
    std::cin >> m>>n;
    int sx,sy,ex,ey;

    for(int i = 0; i < m; ++i)
		path[i].resize(m);

    for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			path[i][j] = {-1,-1};
			char c; cin >> c;
            char_map[i][j]=c;
			if(c == '#')
			{
				mark[i][j] = true;
			}
			if(c == 'A')
			{
				sx = i; sy = j;
			}
			if(c == 'B')
			{
				ex = i; ey = j;
			}
		}
	}
    
    dffs(sx,sy,n,m,-1,-1);

    if(!mark[ex][ey])
	{
		cout << "NO" << endl;
	}
    else{
	cout << "YES" << endl;

	vector<pair<int,int>> ans;
	pair<int,int> end = {ex,ey};
	
	while(!(end.first==sx && end.second==sy))
	{
		ans.push_back(path[end.first][end.second]);
		end.first -= ans.back().first;
		end.second -= ans.back().second;	
	}

	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto c: ans)
	{
		if(c.first == 1 and c.second ==0)
		{
			cout << 'D';
		}
		else if(c.first == -1 and c.second ==0)
		{
			cout << 'U';
		}
		else if(c.first == 0 and c.second == 1)
		{
			cout << 'R';
		}
		else if(c.first == 0 and c.second == -1)
		{
			cout << 'L';
		}
	}
    }
}


// segmentation fault