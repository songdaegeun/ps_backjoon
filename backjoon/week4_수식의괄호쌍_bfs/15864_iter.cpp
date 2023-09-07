#include <iostream>
#include <vector>
using namespace std;

int origin_map[9][9];
int temp_map[9][9];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector< pair<int, int> > cctv;
int unvisible_sp = 0;
int size_x, size_y;
int loop_chk = 0;

int is_oob(int x, int y)
{
    return (x < 0 || x > size_x || y < 0 || y > size_y);
}

void full_dir(int x, int y, int dir, int num)
{
    dir %= 4;
    while(1)
    {
        x += dx[dir];
        y += dy[dir];
        if(is_oob(x, y) || temp_map[x][y] == 6)
            return ;
        if(temp_map[x][y] >= 1 && temp_map[x][y] <= 5)
            continue;
        temp_map[x][y] = num;
    }
}

void check_map();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> size_x >> size_y;
    for(int i = 0; i < size_x; i++)
    {
        for(int j = 0; j < size_y; j++)
        {
            cin >> origin_map[i][j];
            temp_map[i][j] = origin_map[i][j];
            if (origin_map[i][j] != 0 && origin_map[i][j] !=6)
                cctv.push_back(make_pair(i, j));
            else if (origin_map[i][j] == 0)
                unvisible_sp++;
        }
    }
    check_map();
    cout << unvisible_sp << '\n';
}

void check_map()
{
    for(int i = 0; i < (1 << (2 * cctv.size())); i++) // 4의 cctv개수승
    {
        for(int i = 0; i < size_x; i++)
        {
            for(int j = 0; j < size_y; j++)
            {
                temp_map[i][j] = origin_map[i][j];
            }
        }
        int brute = i;
        for(int j = 0; j < cctv.size(); j++)
        {
            int dir = brute % 4;
            brute = brute / 4;
            int x = cctv[j].first;
            int y = cctv[j].second;
            if(origin_map[x][y] == 1)
            {
                full_dir(x, y, dir, 7);
            }
            else if(origin_map[x][y] == 2)
            {
                full_dir(x, y, dir, 7);
                full_dir(x, y, dir + 2, 7);
            }
            else if(origin_map[x][y] == 3)
            {
                full_dir(x, y, dir, 7);
                full_dir(x, y, dir + 1, 7);
            }
            else if(origin_map[x][y] == 4)
            {
                full_dir(x, y, dir, 7);
                full_dir(x, y, dir + 1, 7);
                full_dir(x, y, dir + 2, 7);
            }
            else if(origin_map[x][y] == 5)
            {
                full_dir(x, y, dir, 7);
                full_dir(x, y, dir + 1, 7);
                full_dir(x, y, dir + 2, 7);
                full_dir(x, y, dir + 3, 7);
            }
            int tmp = 0;
            for(int i = 0; i < size_x; i++)
            {
                for(int j = 0; j < size_y; j++)
                {
                    if(temp_map[i][j] == 0)
                        tmp++;
                }
            }
            unvisible_sp = min(unvisible_sp, tmp);
        }
    }
}
