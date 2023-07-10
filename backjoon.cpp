#include <iostream>
using namespace std;

int phone[4];
int map[4][21];

void sol(int step, int path_num, int depth)
{
    if(depth == 10) {
        
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        int backup[4];
        for (int j = 0; j < 4; j++)
        {
            backup[j] = phone[j];
        }
        int tmp_step;
        if(can_set()) {
            cin >> tmp_step;
            step += tmp_step;
            // step에 해당하는 점수 sum
            phone[i] += map[path_num][step];
        }
        for (int j = 0; j < 4; j++)
        {
            phone[j] = backup[j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 4; i++)
    {
        if(i == 0) {
            for (int j = 0; j < 20; j++)
            {
                map[i][j] = (j+1)*2;
            }
        }
        else if(i == 1) {
            for (int j = 0; j < 15; j++)
            {
                map[i][j] = (j+1)*2;
            }
            map[i][16] = 28;
            map[i][17] = 27;
            map[i][18] = 26;
            map[i][19] = 25;
            map[i][20] = 30;
            map[i][21] = 35;
            map[i][22] = 40;
        }
        else if(i == 2) {
            for (int j = 0; j < 10; j++)
            {
                map[i][j] = (j+1)*2;
            }
            map[i][11] = 22;
            map[i][12] = 24;
            map[i][13] = 25;
            map[i][14] = 30;
            map[i][15] = 35;
            map[i][16] = 40;
        }
        else if(i == 3) {
            for (int j = 0; j < 5; j++)
            {
                map[i][j] = (j+1)*2;
            }
            map[i][6] = 13;
            map[i][7] = 16;
            map[i][8] = 19;
            map[i][9] = 25;
            map[i][10] = 30;
            map[i][11] = 35;
            map[i][12] = 40;
        }
    }
    sol(0,0,0);

}