#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int maze[5][5][5];
int maze_board[5][5][5];
int dist[5][5][5];

int min_val = 5 * 4 * 5;
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int dz[6] = {1, -1, 0, 0, 0, 0};

void map_cp(int dist[][5], int src[][5]) {
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dist[i][j] = src[i][j];
        }
    }
}

void rotate(int height, int rot_num) {
    // maze[height][5][5]를 rot_num * 90 degree만큼 clockwise로 rotate.
    int tmp[5][5];
    
    for (int k = 0; k < rot_num; k++)
    {
        map_cp(tmp, maze[height]);
        // 90 degree rotate.
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                maze[height][j][5 - 1 - i] = tmp[i][j];
            }
        }
    }
}

int oob(int x, int y, int z) {
    return (x < 0 || x >= 5 || y < 0 || y >= 5 || z < 0 || z >= 5);
}

int bfs() {
    queue<tuple<int,int,int>> q;
    dist[0][0][0] = 0;
    q.push({0,0,0});

    while(!q.empty()) {
        int x, y, z;
        tie(x,y,z) = q.front(); q.pop();
        for (int i = 0; i < 6; i++)
        {  
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(oob(nx,ny,nz)) continue;
            if(maze[nz][nx][ny] == 0 || dist[nz][nx][ny] != -1) continue;

            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push({nx,ny,nz});
        }
    }
    return (dist[4][4][4]);
}

void calc_dist(int depth) {
    if(depth == 5) {
        if(!(maze[0][0][0] == 0 || maze[4][4][4] == 0))
        {
            memset(dist, -1, sizeof(int) * 5 * 5 * 5);
            int ds = bfs();
            if(ds != -1 && min_val > ds) min_val = ds;
        }
        return ;
    }
    // 원본 복사
    int origin_tmp[5][5];
    map_cp(origin_tmp, maze[depth]);
    for (int i = 0; i < 4; i++)
    {
        rotate(depth, i);
        calc_dist(depth + 1);
        // 원본 복구
        map_cp(maze[depth], origin_tmp);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                cin >> maze_board[i][j][k];
            }
        }
    }
    // 판 1개를 clockwise로 rotate하는 함수 -> rotate();

    // 4가지 상태 존재 가능.
    // 각 상태에 대해서 5번 재귀.
    // 재귀 base condition에서 bfs로 최단 거리 계산하고 min_val값 update.
    
    // *** 판을 쌓는 순서도 바꿀 수 있음. 
 
    vector<int> order = {0, 1, 2, 3, 4};
    do
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    maze[i][j][k] = maze_board[order[i]][j][k];
                }
            }
        }
        calc_dist(0);
    } while (next_permutation(order.begin(), order.end()));
    
    if(min_val == 5 * 4 * 5)
        cout << -1;
    else
        cout << min_val;
    
}

// 1 1 1 1 1
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 1 1 1 1 1
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 1 1 1 1 1
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 1 1 1 1 1
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 1 1 1 1 1
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0