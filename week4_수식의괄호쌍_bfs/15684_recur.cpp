#include <iostream>
#include <vector>
#include <algorithm>
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

void check_map(int depth);
void disp(int map[][9]);

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
    check_map(0);
    cout << unvisible_sp << '\n';
    // cout << "loop:" << loop_chk << "size:" << cctv.size() << '\n';
    // disp();
}

void check_map(int depth)
{
    if (depth == cctv.size())
    {
        loop_chk++;   
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
        return;
    }
    int x = cctv[depth].first;
    int y = cctv[depth].second;
    for(int i = 0; i < 4; i++)
    {
        int back_map[9][9];

        for(int i = 0; i < size_x; i++)
        {
            for(int j = 0; j < size_y; j++)
            {
                back_map[i][j] = temp_map[i][j];
            }
        }
        if(origin_map[x][y] == 1)
        {
            full_dir(x, y, i, 7);
        }
        else if(origin_map[x][y] == 2)
        {
            full_dir(x, y, i, 7);
            full_dir(x, y, i + 2, 7);
        }
        else if(origin_map[x][y] == 3)
        {
            full_dir(x, y, i, 7);
            full_dir(x, y, i + 1, 7);
        }
        else if(origin_map[x][y] == 4)
        {
            full_dir(x, y, i, 7);
            full_dir(x, y, i + 1, 7);
            full_dir(x, y, i + 2, 7);
        }
        else if(origin_map[x][y] == 5)
        {
            full_dir(x, y, i, 7);
            full_dir(x, y, i + 1, 7);
            full_dir(x, y, i + 2, 7);
            full_dir(x, y, i + 3, 7);
        }
        check_map(depth + 1);
        
        for(int k = 0; k < size_x; k++)
        {
            for(int l = 0; l < size_y; l++)
            {
                temp_map[k][l] = back_map[k][l];
            }
        }
    }
    
}

void disp(int map[][9])
{
    cout << '\n';
    for(int i = 0; i < size_x; i++)
    {
        for(int j = 0; j < size_y; j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }    
}