#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

char map[1001][1001];
int visited[1001][1001];
queue<tuple<int,int,int>> q[10];
int step[10];
int cnt_catle[10];
int n,m,p;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bsq() {
    int flag = 0;
    for (int i = 1; i <= p; i++)
    {
        queue<tuple<int,int,int>> next_q;
        while(!q[i].empty()) {
            int x, y, s;
            tie(x,y,s) = q[i].front(); q[i].pop();
            if(s == step[i]) {
                next_q.push({x, y, 0});
                continue;
            }
            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(visited[nx][ny] == 1) continue;
                
                if(map[nx][ny] == '.') {
                    flag = 1;
                    cnt_catle[i]++;
                    visited[nx][ny] = 1;
                    q[i].push({nx, ny, s + 1});
                }
            }
        }
        q[i] = next_q;
    }
    return (flag);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> m >> p;
    for (int i = 1; i <= p; i++)
    {
        cin >> step[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] >= '0' && map[i][j] <= '9') {
                q[map[i][j] - '0'].push({i,j,0});
                cnt_catle[map[i][j] - '0']++;
            }
        }
        
    }
    while(1) {
        if(!bsq())
            break;
    }
    
    for (int i = 1; i <= p; i++)
    {
        cout << cnt_catle[i] << ' ';
    }
    
}

// 3 3 2
// 1 1
// 1..
// ...
// ..2

        