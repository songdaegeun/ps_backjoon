#include <iostream>
using namespace std;

int maze[5][5][5];
int dist[5][5][5];

int min = 5 * 3;
int dx[8] = {, , , , , , , ,};
int dy[8] = {, , , , , , , ,};
int dz[8] = {, , , , , , , ,};

void rotate(int height, int rot_num) {
    // maze[5][5][height]를 rot_num * 90 degree만큼 clockwise로 rotate.
    int tmp[5][5];
    
    for (int i = 0; i < rot_num; i++)
    {
        // 90 degree rotate.
        
    }
    
}

int oob(int x, int y, int z) {
    return (x < 0 || x >= 5 || y < 0 || y >= 5 || z < 0 || z >= 5);
}

int bfs() {

    for (int i = 0; i < 8; i++)
    {  
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nz = z + dz[i];
        if(oob(nx,ny,nz)) continue;
        if(map[nx][ny][nz] == 0 || dist[nx][ny][nz] != -1) continue;

    }
    
}

void calc_dist(int depth) {
    if(depth == 5) {
        memset(dist, -1, sizeof(int) * 5 * 5 * 5)
        int ds = bfs();
        if(min > ds) min = ds;
        return ;
    }
    // 원본 복사
    int origin_tmp[5][5];

    for (int i = 0; i < 4; i++)
    {
        rotate(depth, i);
        calc_dist(depth + 1);
        // 원복 복구

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
                cin >> maze[i][j][k];
            }
        }
    }
    // 판 1개를 clockwise로 rotate하는 함수 -> rotate();

    // 4가지 상태 존재 가능.
    // 각 상태에 대해서 5번 재귀.
    // 재귀 base condition에서 bfs로 최단 거리 계산하고 min값 update.
    calc_dist(0);
    cout << min;
    
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