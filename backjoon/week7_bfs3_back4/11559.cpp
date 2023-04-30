#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

char map[12][6];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void disp_map()
{
	cout << '\n';
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}
void disp_visited(int visited[][6])
{
	cout << '\n';
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << visited[i][j];
		}
		cout << '\n';
	}
}
void bfs()
{
	int visited[12][6];
	memset(visited, 0, sizeof(int) * 12 * 6);
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			int cnt = 0;
			if(visited[i][j] != 0 || map[i][j] == '.') continue;
			queue<pair<int,int>> q;
			char ch = map[i][j];
			visited[i][j] = 1;
			q.push({i, j});
			while(!q.empty())
			{
				pair<int,int> pos = q.front(); q.pop();
				cnt++;
				int x, y;
				tie(x,y) = pos;
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
					if(visited[nx][ny] != 0 || map[nx][ny] == '.' || map[nx][ny] != ch) continue;
					visited[nx][ny] = 1;
					q.push({nx, ny});
				}
			}
			// disp_visited(visited);
			// disp_map();
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					if(visited[i][j] == 1)
					{
						visited[i][j] = 2;	// visitied 2로 변경
						if (cnt >= 4)		// 터질 영역 '*'로 변경
							map[i][j] = '*';
					}
				}
			}
		}
	}
	return ;
}

int down()
{
	int flag = 0;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			int tmp[12];
			if(map[i][j] == '*')
			{
				flag = 1;
				int idx = 0;
				for (int k = 0; k < i; k++)
				{
					tmp[idx++] = map[k][j];
				}
				for (int k = idx; k >= 1; k--)
				{
					map[k][j] = tmp[--idx];
				}
				map[0][j] = '.';
			}
		}
	}
	return (flag);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	for (int i = 0; i < 12; i++)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < 6; j++)
		{
			map[i][j] = str[j];
		}
	}
	int cnt = 0;
	while(1)
	{
		bfs();
		// '*'인 부분 없애면서 down();
		// '*'이 하나도 없다면 down의 return값이 0;
		if(!down())
			break;
		cnt++;
	}
	cout << cnt;
}

// ......
// ......
// ......
// ......
// ......
// ......
// ......
// ......
// .Y....
// .YG...
// RRYG..
// RRYGG.


// ......
// ......
// ......
// ...R.
// ...R..
// ..RR..
// ..RR..
// ......
// .Y....
// .YG...
// RRYG..
// RRYGG.
