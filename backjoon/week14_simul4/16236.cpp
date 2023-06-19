#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int n;
int map[21][21];
int dist[21][21];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class c_shark{
public:
    int size;
    int x;
    int y;
    int eat_cnt;
};

void disp()
{
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    c_shark shark;
    shark.size = 2;
    shark.eat_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 9) {
                shark.x = i;
                shark.y = j;
            }
        }
    }
    int t = 0;
    while(1) {
        // disp();
        vector<int> prey;   // size
        vector<pair<int,int>> prey_pos; // position
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(map[i][j] != 0 && map[i][j] != 9 && map[i][j] < shark.size)
                {
                    // 상좌 우선으로 먹을 수 있는 물고기가 prey_pos에 들어감.
                    prey.push_back(map[i][j]);
                    prey_pos.push_back({i,j});
                }
            }
        }
        if(!prey.size())
            break;
        int min = 400;
        pair<int,int> dest;
        for(auto el:prey_pos) {
            // el.first, el.second와 shark.x, shark.y거리 계산.
            // 상좌 우선으로 먹을 물고기 선택.
            memset(dist, -1, sizeof(dist));
            queue<pair<int,int>> q;
            dist[shark.x][shark.y] = 0;
            q.push({shark.x, shark.y});
            while(!q.empty()) {
                int x, y;
                tie(x, y) = q.front(); q.pop();
                if(x == el.first && y == el.second) {
                    if(min > dist[x][y]) {
                        min = dist[x][y];
                        dest = el;
                    }
                    break;
                }
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(dist[nx][ny] != -1) continue;
                    if(map[nx][ny] > shark.size) continue;
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        if(min == 400)
            break;
        // map 갱신
        map[dest.first][dest.second] = 9;
        map[shark.x][shark.y] = 0;

        // 물고기를 먹고 상태변수 갱신
        shark.x = dest.first;
        shark.y = dest.second;
        shark.eat_cnt++;
        if(shark.size == shark.eat_cnt) {
            shark.size++;
            shark.eat_cnt = 0;
        }
        t += min;
    }
    cout << t << '\n';
}

// sudo:
// map전체를 확인하여 먹을 수 있는 물고기가 존재하는지 확인.
// 존재하지 않는다면 종료.
// 먹을 수 있는 물고기들의 각 거리 계산. (bfs)
// 상좌 우선으로 먹을 물고기 선택.
// 물고기를 먹고 물고기를 먹은 횟수, 아기상어의 크기(현재크기 == 먹은 횟수일때 1만큼 증가), 현재 좌표 갱신

// 상태 변수:
// 물고기를 먹은 횟수
// 아기상어의 크기
// 아기상어의 현재 좌표

// 조건:
// 가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.
// 아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다

// 더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
// 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
// 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
// 거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
// 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.

// 첫째 줄에 공간의 크기 N(2 ≤ N ≤ 20)이 주어진다.
// 둘째 줄부터 N개의 줄에 공간의 상태가 주어진다. 공간의 상태는 0, 1, 2, 3, 4, 5, 6, 9로 이루어져 있고, 아래와 같은 의미를 가진다.

// 0: 빈 칸
// 1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
// 9: 아기 상어의 위치
// 아기 상어는 공간에 한 마리 있다.

// 6
// 1 2 0 3 1 6
// 1 0 5 0 0 0
// 1 0 2 0 2 0
// 0 1 4 0 2 5
// 6 6 3 0 3 3
// 4 9 6 0 2 2