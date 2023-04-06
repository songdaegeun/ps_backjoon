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

    int map[1000][1000];
    // int visit[100][100];
    int date[1000][1000];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    memset(date, -1, sizeof(int) * 1000 * 1000);
    cin >> m >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!(date[i][j] == -1 && map[i][j] == 1)) continue;
            date[i][j] = 0;
            q.push({i, j});
        }
    }
    int min_date = -1;
    while(!q.empty())
    {
        pair<int,int> pos = q.front();
        q.pop();
        int x = pos.first;
        int y = pos.second;
        min_date = date[x][y];
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(oob(nx, ny)) continue;
            if(!(date[nx][ny] == -1 && map[nx][ny] == 0))
                continue;
            date[nx][ny] = date[x][y] + 1;
            q.push({nx, ny});
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (map[i][j] == 0 && date[i][j] == -1)
            {
                min_date = -1;
                break;
            }
        }
    }
    cout << min_date;

}