#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int visited[101][101];
int state[101][101];                        // light
vector<pair<int,int>> bulb_sw[101][101];    // 방마다 0개 이상의 switch를 갖는다.
int n,m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int can_reach(int s_x, int s_y, int d_x, int d_y) {
    queue<tuple<int,int>> q;
    memset(visited, 0, sizeof(int) * 101 *101);
    visited[s_x][s_y] = 1;
    q.push({s_x, s_y});
    while(!q.empty()) {
        int x, y;
        tie(x,y) = q.front(); q.pop();
        if(x == d_x && y == d_y)
            return (1);
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] || !state[nx][ny]) continue;

            visited[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    return (0);
}

int connected(pair<int,int> &pos) {
    int x,y;
    tie(x,y) = pos;
     for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(visited[nx][ny]) return (1);
    }
    return (0);
}

void turn_on(){
    queue<tuple<int,int>> q;
    visited[0][0] = 1;
    q.push({0,0});
    while(!q.empty()) {
        int x,y;
        tie(x,y) = q.front(); q.pop();
        for(auto pos : bulb_sw[x][y]) {
            if(visited[pos.first][pos.second]) continue;
            if(connected(pos)) {
                visited[pos.first][pos.second] = 1;
                q.push({pos.first, pos.second});
            }

            state[pos.first][pos.second] = 1;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] || !state[nx][ny]) continue;

            visited[nx][ny] = 1;
            q.push({nx,ny});
        }
        
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        bulb_sw[x - 1][y - 1].push_back({a - 1,b - 1});
    }

    state[0][0] = 1;
    // 그 방의 모든 sw를 켜는 함수
    turn_on();
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(state[i][j] == 1)
                ans++;
        }
    }
    cout << ans << '\n';
}


// 초기에는 1,1만 불이 켜져있고 여기서 출발한다.
// 불이 켜져있는 인접영역으로만 이동가능하다.
// 불을 켤 수 있는 방의 최대 개수를 출력한다.

// 각 방에서 켤수있는 모든 불을 켠다.
// 인접영역을 확인하며 불이 켜져있다면 방문.


// 3 6
// 1 1 1 2
// 2 1 2 2
// 1 1 1 3
// 2 3 3 1
// 1 3 1 2
// 1 3 2 1

// 3 2
// 1 1 2 2
// 2 2 1 1