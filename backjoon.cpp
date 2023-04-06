#include <iostream>
using namespace std;

int n,m;
int row, col;
int map[40][40];

int is_oob(int x, int y)
{
    return (x < 0 || x >= n|| y < 0 || y >= m);
}

void stick_to_map(int sticker[][40]);

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

void stick_to_map(int sticker[][40])
{
    // 좌상단 우선하여 붙힘
    for(int i = 0; i < n; i++)
    { 
        for(int j = 0; j < m; j++)
        { 
            // 스티커 붙히기 시도
            for(int dir = 0; dir < 4; dir++)
            {
                int ret = try_stick(i, j, dir, sticker);
                if (ret)
                    return;
            }
        }
    }
}

int try_stick(int x, int y, int dir, int sticker[][40])
{
    int tmp_sticker[40][40];
    for(int i = 0; i < row; i++)
    { 
        for(int j = 0; j < col; j++)
        { 
            tmp_sticker[i][j] = sticker[i][j];
        }
    }
    rotate_sticker(tmp_sticker, dir);
    for(int i = 0; i < row; i++)
    { 
        for(int j = 0; j < col; j++)
        {
            if (is_oob(i, j))
                return (0);
            if (map[x + i][y + j] == 1)
                return (0);
            map[x + i][y + j] = tmp_sticker[i][j];
        }
    }
    return (1);
}

void rotate_sticker(int tmp_sticker[][40], int dir)
{
    // 90도 회전변환행렬계산
}