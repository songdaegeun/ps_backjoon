#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;


int n,m;
int map[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int is_tetro(vector<pair<int,int>> &select) {
	int select_pos[4][4];
	int visited[4][4];
	memset(select_pos, 0, sizeof(int) * 4 * 4);
	memset(visited, 0, sizeof(int) * 4 * 4);
	for(auto el:select)
		select_pos[el.first][el.second] = 1;

	pair<int,int> pos = select.front();
	
	queue<pair<int,int>> q;
	visited[pos.first][pos.second] = 1;
	q.push({pos.first, pos.second});

	int space = 0;
	while(!q.empty()) {
		int x, y;
		tie(x,y) = q.front(); q.pop();
		space++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
			if(visited[nx][ny]) continue;
			if(select_pos[nx][ny]) {
				visited[nx][ny] = 1;
				q.push({nx,ny});
			}
		}
	}
	if(space == 4)
		return (1);
	else
		return (0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	// 16개의 좌표 중, 4개를 임의로 고른다.
	// 고른 4개의 좌표가 서로 인접했는지 && 크기가 4인지 확인한다.
	vector<int> mask(16, 0);
	for (int i = 12; i < 16; i++)
		mask[i] = 1;
	vector<vector<pair<int,int>>> tetro;
	do {
		vector<pair<int,int>> select_pos;
		for (int i = 0; i < 16; i++)
		{
			if(mask[i]) {
				pair<int,int> pos;
				pos.first = i/4;
				pos.second = i%4;
				select_pos.push_back(pos);
			}
		}
		if (is_tetro(select_pos)) {
			tetro.push_back(select_pos);
		}

	} while(next_permutation(mask.begin(), mask.end()));

	int ans = 0;
	for (int i = 0; i <= n - 4; i++)
	{
		for (int j = 0; j <= m - 4; j++)
		{
			for(auto selected_pos : tetro) {
				int tot = 0;
				for(auto pos : selected_pos) {
					tot += map[i + pos.first][j + pos.second];
				}
				if(ans < tot)
					ans = tot;
			}
		}
	}
	cout << ans << '\n';

}