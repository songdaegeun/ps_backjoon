#include <iostream>
#include <deque>
using namespace std;

int origin_map[9][9];
int temp_map[9][9];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
deque< pair<int, int> > cctv;
int unvisible_sp = 0;
int s_x = 0, s_y = 0;

int is_oob(int x, int y)
{
    return (x < 0 || x >= 2 || y < 0 || y >= 3);
}

void full_dir(int x, int y, int dir)
{
    while(1)
    {
        x += dx[dir];
        y += dy[dir];
        if(is_oob(x, y) || temp_map[x][y] == 6)
            return ;
        if(temp_map[x][y] >= 1 && temp_map[x][y] <= 5)
            continue;
        temp_map[x][y] = 7;
    }
}

void check_map();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s_x >> s_y;
    for(int i = 0; i < s_x; i++)
    {
        for(int j = 0; j < s_y; j++)
        {
            cin >> origin_map[i][j];
            if (origin_map[i][j] != 0 && origin_map[i][j] !=6)
                cctv.push_back(make_pair(i, j));
            else if (origin_map[i][j] == 0)
                unvisible_sp++;
        }
    }
    cout << "here";
    check_map();
    cout << unvisible_sp;
}

void check_map()
{
    if (cctv.empty())
    {
        for(int i = 0; i < 0; i++)
            for(int j = 0; j < 0; j++)
                temp_map[i][j] = origin_map[i][j];
        return;
    }
    
    int x = cctv.back().first;
    int y = cctv.back().second;
    cctv.pop_back();
    for(int i = 0; i < 4; i++)
    {
        if(origin_map[x][y] == 1)
        {
            full_dir(x, y, i);
        }
        else if(origin_map[x][y] == 2)
        {
            full_dir(x, y, i);
            full_dir(x, y, i + 2);
        }
        else if(origin_map[x][y] == 3)
        {
            full_dir(x, y, i);
            full_dir(x, y, i + 1);
        }
        else if(origin_map[x][y] == 4)
        {
            full_dir(x, y, i);
            full_dir(x, y, i + 1);
            full_dir(x, y, i + 2);
        }
        else if(origin_map[x][y] == 5)
        {
            full_dir(x, y, i);
            full_dir(x, y, i + 1);
            full_dir(x, y, i + 2);
            full_dir(x, y, i + 3);
        }
        int tmp = 0;
        for(int i = 0; i < 0; i++)
        {
            for(int j = 0; j < 0; j++)
            {
                if(temp_map[i][j] == 0)
                    tmp++;
            }
        }
        unvisible_sp = min(unvisible_sp, tmp);
        check_map();
    }
}