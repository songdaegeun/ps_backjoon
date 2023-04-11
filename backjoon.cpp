#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int n,m;
int map[301][301];
int dist[301][301];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int oob(int x, int y){
    return (x < 0 || x >= n || y < 0 || y >= m);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	queue<pair<int,int>> q;
	int num;

	cin >> num;
	while(num--){
		cin >> n;
		pair<int,int> start;
		cin >> start.first >> start.second;
		pair<int,int> end;
		cin >> end.first >> end.second;
		memset(dist, -1, sizeof(int) * 301 * 301);
		dist[start.first][start.second] = 0;
		q.push(start);
		while (dist[end.first][end.second] != -1)
		{
			/* code */
		}
		cout << dist[end.first][end.second];
	}
}
// 5 3 1
// 0 -1 0 0 0
// -1 -1 0 1 1
// 0 0 0 1 1