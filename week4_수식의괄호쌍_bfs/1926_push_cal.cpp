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

    int map[501][501];
    int visit[501][501];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    cin >> n >> m;
    for(int i = 0; i <n; i++)
    {
        for(int j = 0; j <m; j++)
        {
            cin >> map[i][j];
        }        
    }
    queue<pair<int,int>> q;
    memset(visit, 0, sizeof(int) * 501 * 501);
    int cnt = 0;
    int max = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int space = 0;
            if(!visit[i][j] && map[i][j] == 1)
            {
                cnt++;
                space++;
                visit[i][j] = 1;
                q.push({i,j});
            }
            while(!q.empty())
            {
                pair<int,int> pos = q.front();
                q.pop();
                int x = pos.first;
                int y = pos.second;
                for(int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(oob(nx,ny)) continue;
                    if (!(!visit[nx][ny] && map[nx][ny] == 1))
                        continue;
                    space++;
                    visit[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            if (max < space)
                max = space;
        }
    }
    cout << cnt << '\n' << max << '\n';
}

