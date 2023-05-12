#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int map[201][201];
int dist[201][201][31];
int h_dx[8] = {2, 2, 1, -1, -2, -2, 1, -1}; // horse
int h_dy[8] = {1, -1, 2, 2, 1, -1, -2, -2};
int m_dx[4] = {1, 0, -1, 0};                // monkey
int m_dy[4] = {0, 1, 0, -1};

int k, r, c;

int bfs() {
    // 말로 k번 뛸 수 있다.
    queue<tuple<int,int,int>> q;
    dist[0][0][0] = 0;
    q.push({0,0,0});
    while(!q.empty()) {
        int x, y, m_k;
        tie(x, y, m_k) = q.front(); q.pop();
        if(x == r - 1 && y == c - 1)
            return (dist[x][y][m_k]);
        // 말로 뛰기
        for (int i = 0; i < 8; i++)
        {
            int nx = x + h_dx[i];
            int ny = y + h_dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(map[nx][ny] == 1 || m_k == k) continue;
            if(dist[nx][ny][m_k + 1] != -1) continue;
            dist[nx][ny][m_k + 1] = dist[x][y][m_k] + 1;
            q.push({nx, ny, m_k + 1});
        }
        // 원숭이로 뛰기
        for (int i = 0; i < 4; i++)
        {            
            int nx = x + m_dx[i];
            int ny = y + m_dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(map[nx][ny] == 1) continue;
            if(dist[nx][ny][m_k] != -1) continue;
            dist[nx][ny][m_k] = dist[x][y][m_k] + 1;
            q.push({nx, ny, m_k});
        }
    }
    return (-1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> c >> r;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }
    memset(dist, -1, sizeof(int) * 201 * 201 * 31);
    int ans = bfs();
    cout << ans;
}

// 2
// 5 2
// 0 0 1 1 0
// 0 0 1 1 0