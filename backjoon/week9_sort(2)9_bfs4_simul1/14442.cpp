#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m, k;
char map[1001][1001];
int dist[1001][1001][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<tuple<int,int,int>> q;
    dist[0][0][0] = 1;
    q.push({0,0,0});
    while(!q.empty()) {
        int x, y, cnt_break;
        tie(x,y,cnt_break) = q.front(); q.pop();
        if(x == n - 1 && y == m - 1)
            return (dist[x][y][cnt_break]);
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int n_cnt_break = cnt_break;
            if(map[nx][ny] == 1 ) n_cnt_break++;
            if(n_cnt_break > k || dist[nx][ny][n_cnt_break] != 0) continue;
    
            dist[nx][ny][n_cnt_break] = dist[x][y][cnt_break] + 1;
            q.push({nx,ny,n_cnt_break});
        }
        
    }
    return (-1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        for (int j = 0; j < m; j++) {
            map[i][j] = str[j] - '0';
        }
    }
    int ans = bfs();
    cout << ans;
}

// 6 4 1
// 0100
// 1110
// 1000
// 0000
// 0111
// 0000