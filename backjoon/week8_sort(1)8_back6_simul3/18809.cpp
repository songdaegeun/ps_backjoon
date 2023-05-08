#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

#define GREEN 1
#define RED 2
#define FLOWER 3
using namespace std;

int n, m, g, r;
int map[51][51];
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int,int>> gr_v;

int bsq(vector<int>& mask)
{
	int cnt = 0;
	queue<pair<int,int>> q;
	pair<int,int> state[51][51] = {};

	for (int i = 0; i < gr_v.size(); i++)
	{
		if(mask[i] == RED || mask[i] == GREEN)
		{
			state[gr_v[i].first][gr_v[i].second] = {0, mask[i]};
			q.push(gr_v[i]);
		}	
	}
	while(!q.empty())
	{
		int x, y;
		tie(x,y) = q.front(); q.pop();
		int time = state[x][y].first;
		int color = state[x][y].second;
		if(state[x][y].second == FLOWER) continue;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(map[nx][ny] == 0) continue;
			
			if(state[nx][ny].second == 0)
			{
				state[nx][ny] = {time + 1, color};
				q.push({nx, ny});
			}
			else if(state[nx][ny].second == GREEN)
			{
				if(color == RED && time + 1 == state[nx][ny].first)
				{
					cnt++;
					state[nx][ny].second = FLOWER;
				}
			}
			else if(state[nx][ny].second == RED)
			{
				if(color == GREEN && time + 1 == state[nx][ny].first)
				{
					cnt++;
					state[nx][ny].second = FLOWER;
				}
			}
		}
	}
	return (cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> m >> g >> r;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 2)
				gr_v.push_back({i, j});
		}
	}
	vector<int> mask(gr_v.size(), 0);
	for (int i = 0; i < gr_v.size(); i++)
	{
		if(gr_v.size() - r <= i)
			mask[i] = RED;
		else if(gr_v.size() - g - r <= i)
			mask[i] = GREEN;
	}

	do
	{
		int cnt = bsq(mask);
		if(ans < cnt) ans = cnt;
	} while (next_permutation(mask.begin(), mask.end()));
	cout << ans;
}

// 3 3 2 1
// 2 1 0
// 1 0 1
// 2 1 2