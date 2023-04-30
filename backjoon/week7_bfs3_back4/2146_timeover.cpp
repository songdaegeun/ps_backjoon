#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int map[101][101];
int visited[101][101];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int min_val;

void disp_map()
{
	for (int i = 0; i < n; i++)
	{
		cout << '\n';
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << ' ';
		}
	}
}
// bfs_map_chk()로 대륙마다 visited = 1, 2, 3... chk.
int bfs_map_chk()
{
	queue<pair<int,int>> q;
	int conti_num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(map[i][j] != 1 || visited[i][j] != 0) continue;
			conti_num++;
			visited[i][j] = conti_num;
			q.push({i, j});
			while(!q.empty())
			{
				pair<int,int> pos = q.front(); q.pop();
				int x, y;
				tie(x,y) = pos;
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(map[nx][ny] != 1 || visited[nx][ny] != 0) continue;
					visited[nx][ny] = conti_num;
					q.push({nx, ny});
				}
			}
		}
	}
	return (conti_num);
}

// conti_1, conti_2간 좌표차이로 거리 계산
// 여기서 O(N^4)이고 comb_dist까지하면 O(N^6)이라서 timeover.
void dist(int conti_1, int conti_2)
{
	for (int x1 = 0; x1 < n; x1++)
	{
		for (int y1 = 0; y1 < n; y1++)
		{
			if(visited[x1][y1] == conti_1)
			{
				for (int x2 = 0; x2 < n; x2++)
				{
					for (int y2 = 0; y2 < n; y2++)
					{
						if(visited[x2][y2] == conti_2)
						{
							int distance = abs(x1 - x2) + abs(y1 - y2) - 1;
							if(distance == 0)
								cout << "here" << x1 << ' ' << y1 << ' '<< x2 << ' '<< y2 << ' ';
							min_val = min(min_val, distance);
						}
					}
				}
			}
		}
	}
}

void comb_dist(int conti_num, int start_i)
{
	for (int i = start_i + 1; i <= conti_num; i++)
	{
		dist(start_i, i);
		comb_dist(conti_num, start_i + 1);
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	min_val = 2 * n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	int conti_num;
	conti_num = bfs_map_chk();
	// 대륙의 개수 conti_num에 대해 vector<int> (conti_num, 0)으로 잡고, next_permutation으로 2개 선택(conti_1, conti_2).
	comb_dist(conti_num, 1);
	// 최소값 출력
	cout << min_val;
}

// 10
// 1 1 1 0 0 0 0 1 1 1
// 1 1 1 1 0 0 0 0 1 1
// 1 0 1 1 0 0 0 0 1 1
// 0 0 1 1 1 0 0 0 0 1
// 0 0 0 1 0 0 0 0 0 1
// 0 0 0 0 0 0 0 0 0 1
// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 1 1 0 0 0 0
// 0 0 0 0 1 1 1 0 0 0
// 0 0 0 0 0 0 0 0 0 0