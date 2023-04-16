#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int n;
int l, r, c;
char map[31][31][31];
int dist[31][31][31];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void disp_map();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	while(1)
	{
		tuple<int,int,int> s_pt;
		tuple<int,int,int> e_pt;
		memset(dist, -1, sizeof(int) * 31 * 31 * 31);
		cin >> l >> r >> c;
		cin.ignore();
		if (!l && !r && !c) break;
		for(int k = 0; k < l; k++)
		{
			string str;
			for(int i = 0; i < r; i++)
			{
				getline(cin, str);
				for(int j = 0; j < c; j++)
				{
					map[i][j][k] = str[j];
					if(map[i][j][k] == 'S')
						s_pt = make_tuple(i, j, k);
					else if(map[i][j][k] == 'E')
						e_pt = make_tuple(i, j, k);
				}
			}
			cin.ignore();
		}
		// cout << get<0>(s_pt) << ' ' << get<1>(s_pt) << ' ' << get<2>(s_pt) << '\n';
		// cout << get<0>(e_pt) << ' ' << get<1>(e_pt) << ' ' << get<2>(e_pt) << '\n';
		
		queue<tuple<int,int,int>> q;
		dist[get<0>(s_pt)][get<1>(s_pt)][get<2>(s_pt)] = 0;
		q.push(s_pt);
		while(!q.empty())
		{
			tuple<int,int,int> pos = q.front();
			q.pop();
			int x, y, z;
			tie(x, y, z) = pos;
			for(int i = 0; i < 6; i++)
			{
				int nx, ny, nz;
				nx = x + dx[i];
				ny = y + dy[i];
				nz = z + dz[i];
				if(nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
				if(dist[nx][ny][nz] != -1 || map[nx][ny][nz] == '#') continue;
				dist[nx][ny][nz] = dist[x][y][z] + 1;
				q.push(make_tuple(nx, ny, nz));
			}
		}
		if(dist[get<0>(e_pt)][get<1>(e_pt)][get<2>(e_pt)] == -1)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << dist[get<0>(e_pt)][get<1>(e_pt)][get<2>(e_pt)] <<  "minute(s).\n";
	}
}

void disp_map()
{
	for(int k = 0; k < l; k++)
	{
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				cout << map[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	cout << '\n';
}