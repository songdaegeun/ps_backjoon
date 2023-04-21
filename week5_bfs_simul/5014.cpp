#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int map[1000001];
int dist[1000001];
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
int dx[2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int f, s, g, u, d;
	queue<int> q;

	cin >> f >> s >> g >> u >> d;
	dx[0] = u;
	dx[1] = -1 * d;
	memset(dist, -1, sizeof(int) * 1000001);
	dist[s] = 0;
	q.push(s);
	while(dist[g] == -1) 
	{
		if(q.empty())
		{
			cout << "use the stairs";
			return 0;
		}
		int x = q.front();
		q.pop();
		for(int i = 0; i < 2; i++)
		{
			int nx = x + dx[i];
			if (nx < 1 || nx > f) continue;
			if (dist[nx] != -1) continue;
			dist[nx] = dist[x] + 1;
			q.push(nx);
		}
	}
	cout << dist[g];
}

// 10 1 10 2 1