#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int tc, n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void disp_map(char map[103][103])
{
    cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int bsq(char map[][103], int *keys)
{
    queue<pair<int,int>> q;         // 방문할 큐.
    queue<pair<int,int>> door[26];  // 열지못한 문의 큐.
    int visited[103][103];
    memset(visited, 0, sizeof(visited));
    visited[0][0] = 1;
    q.push({0, 0});
    int cnt = 0;
    while(!q.empty())
    {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n + 2 || ny < 0 || ny >= m + 2) continue;
            // '*' or gate or '$' or '.' or key
            if(map[nx][ny] == '*' || visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            if(map[nx][ny] >= 'A' && map[nx][ny] <= 'Z')
            {
                if(!keys[map[nx][ny] - 'A']) {
                    door[map[nx][ny] - 'A'].push({nx, ny});
                }
                else {
                    q.push({nx, ny});
                }
                    
            }
            else if(map[nx][ny] >= 'a' && map[nx][ny] <= 'z')
            {
                keys[map[nx][ny] - 'a'] = 1;
                while(!door[map[nx][ny] - 'a'].empty()) {  // 열지 못한 문 map[nx][ny] - 'a' + 'A'가 1개 이상 존재한다면 방문할 큐에 넣어줌.
                    q.push(door[map[nx][ny] - 'a'].front()); door[map[nx][ny] - 'a'].pop();
                }
                q.push({nx, ny});
            }
            else
            {
                if(map[nx][ny] == '$')
                    cnt++;
                q.push({nx, ny});
            }
        }
    }
    
    return (cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        char map[103][103];
        memset(map, 0, sizeof(map));
        int keys[26];
        memset(keys, 0, sizeof(keys));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cin >> map[i][j];
        }
        cin.ignore();
        string tmp;
        getline(cin, tmp);
        if (tmp != "0")
        {
            for (auto ch: tmp)
                keys[ch - 'a'] = 1;
        }
        // disp_map(map);
        // for (int i = 0; i < 26; i++)
        //     cout << keys[i] << ' ';
        // cout << '\n';
        cout << bsq(map, keys) << '\n';
    }
    // 모든 입구를 queue에 넣는다.
    // 키에 해당하는 문은 통과한다.
    // 키를 획득하면 keys에 추가한다.
}

// 3
// 5 17
// *****************
// .............**$*
// *B*A*P*C**X*Y*.X.
// *y*x*a*p**$*$**$*
// *****************
// cz
// 5 11
// *.*********
// *...*...*x*
// *X*.*.*.*.*
// *$*...*...*
// ***********
// 0
// 7 7
// *ABCDE*
// X.....F
// W.$$$.G
// V.$$$.H
// U.$$$.J
// T.....K
// *SQPML*
// irony