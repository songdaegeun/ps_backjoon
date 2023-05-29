#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

char map[1001][1001];
int visited[1001][1001];
int step[10];
int cnt_catle[10];
int n,m,p;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void disp_map() {
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

void push_catle(queue<tuple<int,int,int,int>> &q, int catle) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] - '0' == catle) {
                visited[i][j] = 1;
                q.push({i,j, catle, 0});
            }
        }
    }
}

int bsq(int catle) {
    // map[] != '.'이면 성.
    // 성은 i(1부터 p)까지의 순서로 확장됨.
    // 각 확장에서 step[i]번 인접영역으로 확장됨.
    // i의 영역을 공백구분하여 출력.
    // memset(visited, 0, sizeof(int) * 1001 * 1001);
    queue<tuple<int,int,int,int>> q;
    push_catle(q, catle);
    int flag = 0;

    while(!q.empty()) {
        int x, y, c, s;
        tie(x,y,c,s) = q.front(); q.pop();
        // 1. step[c]만큼 4방향으로 확장한다.
        // 2. 큐에 있는 그 다음 좌표에 대해서 1을 수행한다.
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] == 1) continue;
            if(s == step[c]) continue;
            if(map[nx][ny] == '.') {
                flag = 1;
                cnt_catle[c]++;
                map[nx][ny] = c + '0';
                visited[nx][ny] = 1;
                q.push({nx, ny, c, s + 1});
            }
        }
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
                cnt_catle[map[i][j] - '0']++;
            }
        }
        
    }
    int break_cnt = 0;
    while(1) {
        break_cnt = 0;
        for (int i = 1; i <= p; i++)
        {
            if(!bsq(i)) {
                break_cnt++;
            }
        }
        if(break_cnt == p)
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

        