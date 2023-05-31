#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int n, m;
int map[9][9];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void disp() {
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

void copy_map(int dst[9][9], int src[9][9]) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dst[i][j] = src[i][j];
        }
    }
}

int bsq(int tmp_map[9][9]) {
    int cnt = 0;
    int visited[9][9];
    memset(visited, 0, sizeof(visited));
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(tmp_map[i][j] == 2) {
                visited[i][j] = 1;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()) {
        int x,y;
        tie(x,y) = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] != 0) continue;
            if(tmp_map[nx][ny] == 1) continue;
            visited[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(visited[i][j] == 0 && tmp_map[i][j] != 1)
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 0중에서 임의로 3개를 선택한다.
    // 2가 퍼지게한다.
    // 안전영역의 최대값을 계산한다.
    cin >> n >> m;
    vector<pair<int,int>> empty_pos;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];   
            if(map[i][j] == 0)
                empty_pos.push_back({i,j});
        }
        
    }
    int max = 0;
    vector<int> mask(empty_pos.size(), 0);
    for (int i = empty_pos.size() - 3; i < empty_pos.size(); i++)
        mask[i] = 1;
    do
    {
        int tmp_map[9][9];
        copy_map(tmp_map, map);
        for (int i = 0; i < empty_pos.size(); i++)
        {
            if(mask[i] == 1) {
                tmp_map[empty_pos[i].first][empty_pos[i].second] = 1;
            }
        }
        int safety_area = bsq(tmp_map);
        // 안전영역의 최대값 계산
        if(max < safety_area) {
            max = safety_area;
        }
    } while (next_permutation(mask.begin(), mask.end()));
    
    cout << max << '\n';
}
// 안전영역(바이러스가 퍼질 수 없는곳)의 최대값 출력.


// 7 7
// 2 0 0 0 1 1 0
// 0 0 1 0 1 2 0
// 0 1 1 0 1 0 0
// 0 1 0 0 0 0 0
// 0 0 0 0 0 1 1
// 0 1 0 0 0 0 0
// 0 1 0 0 0 0 0