#include <iostream>
#include <algorithm>
using namespace std;

int map[21][21];
int m, n, x, y, command_n;
int command[1001];
int dice[6];

void rolling_dice(int com)
{
    int tmp[4];
    
    if(com == 1)
    {
        tmp[0] = dice[0];
        tmp[1] = dice[2];
        tmp[2] = dice[5];
        tmp[3] = dice[3];
        rotate(tmp, tmp + 1, tmp + 4);
        dice[0] = tmp[0];
        dice[2] = tmp[1];
        dice[5] = tmp[2];
        dice[3] = tmp[3];        
    }
    else if(com == 2)
    {
        tmp[0] = dice[0];
        tmp[1] = dice[2];
        tmp[2] = dice[5];
        tmp[3] = dice[3];
        rotate(tmp, tmp + 3, tmp + 4);
        dice[0] = tmp[0];
        dice[2] = tmp[1];
        dice[5] = tmp[2];
        dice[3] = tmp[3];          
    }
    else if(com == 3)
    {
        tmp[0] = dice[1];
        tmp[1] = dice[0];
        tmp[2] = dice[4];
        tmp[3] = dice[5];
        rotate(tmp, tmp + 1, tmp + 4);
        dice[1] = tmp[0];
        dice[0] = tmp[1];
        dice[4] = tmp[2];
        dice[5] = tmp[3];        
    }
    else if(com == 4)
    {
        tmp[0] = dice[1];
        tmp[1] = dice[0];
        tmp[2] = dice[4];
        tmp[3] = dice[5];
        rotate(tmp, tmp + 3, tmp + 4);
        dice[1] = tmp[0];
        dice[0] = tmp[1];
        dice[4] = tmp[2];
        dice[5] = tmp[3];        
    }
    if(map[x][y])
    {
        dice[5] = map[x][y];
        map[x][y] = 0;
    }
    else
        map[x][y] = dice[5];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> n >> m >> x >> y >> command_n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < command_n; i++) cin >> command[i];
    // x, y부터시작해서 command_n만큼 루프를 돈다.
    // 각 루프마다 map의 요소가 0이면 주사위의 바닥면이 map으로 복사되고, 0이아니면 요소가 주사위의 바닥면에 복사되며 요소는 0이된다.
    // 각 루프마다 구를수있는 4가지 경우에 대한 함수를 작성한다.
    // 각 루프마다 주사위 윗면을 출력한다.
    // dice[4]와 map[x][y]비교 
    if(map[x][y])
    {
        dice[5] = map[x][y];
        map[x][y] = 0;
    }
    else
        map[x][y] = dice[5];
    for (int i = 0; i < command_n; i++)
    {
        int nx = x;
        int ny = y;
        if(command[i] == 1)
            ny = y + 1;
        else if(command[i] == 2)
            ny = y - 1;
        else if(command[i] == 3)
            nx = x - 1;
        else if(command[i] == 4)
            nx = x + 1;
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        x = nx;
        y = ny;
        rolling_dice(command[i]);
        cout << dice[0] << '\n';
    }
    
	
}

// 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4

// 4 2 0 0 8
// 0 2
// 3 4
// 5 6
// 7 8
// 4 4 4 1 3 3 3 2