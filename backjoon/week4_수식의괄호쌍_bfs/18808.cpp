#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n,m;
int row, col;
int map[40][40];

void stick_to_map(int sticker[][40]);
int try_stick(int x, int y, int dir, int sticker[][40]);
void disp_sticker(int sticker[][40], int row, int col);
int rotate_sticker(int tmp_sticker[][40]);

void swap_r_c()
{
    int tmp;

    tmp = row;
    row = col;
    col = tmp;
}

void disp_map()
{
    for(int i = 0; i < n; i++)
    { 
        for(int j = 0; j < m; j++)
        { 
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void disp_sticker(int sticker[][40], int row, int col)
{
     for(int i = 0; i < row; i++)
    { 
        for(int j = 0; j < col; j++)
        { 
            cout << sticker[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int rotate_sticker(int tmp_sticker[][40])
{
    int ret_sticker[40][40];

    for(int i = 0; i < row; i++)
    { 
        for(int j = 0; j < col; j++)
        {
            ret_sticker[i][j] = tmp_sticker[i][j];
        }
    }
    // for(int i = 0; i < col; i++)
    //     for(int j = 0; j < row; j++)
    //         tmp_sticker[i][j] = ret_sticker[row -1 -j][i];

    for(int i = 0; i < row; i++)
    { 
        for(int j = 0; j < col; j++)
        {
            tmp_sticker[j][row - 1 - i] = ret_sticker[i][j];
        }
    }
    swap_r_c();
    return (1);
}

void stick_to_map(int sticker[][40])
{
    for(int dir = 0; dir < 4; dir++)
    {
        // 좌상단 우선하여 붙힘
        for(int i = 0; i <= n - row; i++)
        { 
            for(int j = 0; j <= m - col; j++)
            { 
                int ret = try_stick(i, j, dir, sticker);
                if (ret)
                    return;
            }
        }
        rotate_sticker(sticker);
        // rotate(sticker);
    }
}

int try_stick(int x, int y, int dir, int sticker[][40])
{
    for(int i = 0; i < row; i++)
    { 
        for(int j = 0; j < col; j++)
        {
            if (map[x + i][y + j] == 1 && sticker[i][j] == 1)
                return (0);
        }
    }
    for(int i = 0; i < row; i++)
    { 
        for(int j = 0; j < col; j++)
        {
            if (sticker[i][j])
                map[x + i][y + j] = sticker[i][j];
        }
    }
    return (1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int visit[100][100];
    // int date[1000][1000];
    // int dx[4] = {1, 0, -1, 0};
    // int dy[4] = {0, 1, 0, -1};
    int num;

    cin >> n >> m >> num;
    for(int i = 0; i < num; i++)
    {  
        cin >> row >> col;
        int sticker[40][40];
        for(int j = 0; j < row; j++)
        { 
            for(int k = 0; k < col; k++)
            { 
                cin >> sticker[j][k];
            }
        }
        // map 에 sticker 붙힘
        stick_to_map(sticker);
        // disp_map();
    }
    // map에서 sticker가 붙은 개수(1의 개수) 출력
    int res = 0;
    for(int i = 0; i < n; i++)
    { 
        for(int j = 0; j < m; j++)
        {
            res += (map[i][j] == 1);
        }
    }
    cout << res;
}

// 5 4 1
// 3 3
// 1 0 1
// 1 1 1
// 1 0 1

// 5 4 1
// 2 5
// 1 1 1 1 1
// 0 0 0 1 0