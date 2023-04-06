#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;

int oob(int x, int y)
{
    return (x < 0 || x >= n|| y < 0 || y >= m);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int map[100][100];
    int visit[100][100];
    int dist[100][100];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    string str;

    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        getline(cin, str);
        for(int j = 0; j < m; j++)
        {
            map[i][j] = str[j] - '0';
        }
    }
    memset(visit, 0, sizeof(int) * 100 * 100);
    memset(dist, -1, sizeof(int) * 100 * 100);
    queue<pair<int,int>> q;
    visit[0][0] = 1;
    dist[0][0] = 1;
    q.push({0, 0});
    while(!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();
        int x = pos.first;
        int y = pos.second;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(oob(nx, ny)) continue;
            if(visit[nx][ny] || map[nx][ny] == 0) continue;
            visit[nx][ny] = 1;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << dist[n - 1][m - 1];
}

// 4 6
// 101111
// 101010
// 101011
// 111011