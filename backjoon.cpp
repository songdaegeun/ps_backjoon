#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int map[40][40];

int oob(int x, int y)
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
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int num;

    cin >> n >> m >> num;
    for(int i = 0; i < num; i++)
    {  
        int row, col;
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
    // 실패시 시계방향 회전
}