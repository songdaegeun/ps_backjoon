#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int map[100][100];
int visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	string str;
	queue<pair<int,int>> q;

	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; i++)
	{
		getline(cin, str);
		for(int j = 0; j < n; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}
	vector<int> dangi;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(visited[i][j] || map[i][j] == 0) continue;
			visited[i][j] = 1;
			q.push({i,j});
			int area = 0;
			while(!q.empty())
			{
				pair<int,int> pos = q.front();
				q.pop();
				area++;
				int x = pos.first;
				int y = pos.second;
				for(int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(visited[nx][ny] || map[nx][ny] == 0) continue;
					visited[nx][ny] = 1;
					q.push({nx,ny});
				}
			}
			dangi.push_back(area);
		}
	}
	sort(dangi.begin(), dangi.end());
	cout << dangi.size() << '\n';
	for(int i = 0; i < dangi.size(); i++)
	{
		cout << dangi[i] << '\n';
	}

}

// 7
// 0110100
// 0110101
// 1110101
// 0000111
// 0100000
// 0111110
// 0111000