#include <iostream>
#include <deque>
using namespace std;

class c_cctv_info
{
    public:
        int x;
        int y;
        char type;
};
int get_cctv_info(deque<c_cctv_info> *p_deq, int map[][9]);
int visible_area_chk(deque<c_cctv_info> deq, int map[][9], int *p_max);
int chk_area(int map[][9]);
void cctv_1(int dir, int *p_max, int map[][9], int x, int y, int ch);
void cctv_2(int dir, int *p_max, int map[][9], int x, int y, int ch);
void cctv_3(int dir, int *p_max, int map[][9], int x, int y, int ch);
void cctv_4(int dir, int *p_max, int map[][9], int x, int y, int ch);
void cctv_5(int *p_max, int map[][9], int x, int y, int ch);
void right_fill(int x, int y, int map[][9], int *p_max, int ch);
void left_fill(int x, int y, int map[][9], int *p_max, int ch);
void up_fill(int x, int y, int map[][9], int *p_max, int ch);
void down_fill(int x, int y, int map[][9], int *p_max, int ch);

int n, m;
int origin_map[9][9];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, visible_area, max;
    int map[9][9];
    int cnt_cctv;

    deque<c_cctv_info> deq;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> num;
            map[i][j] = num;
            origin_map[i][j] = num;
        }
    }
    max = 0;
    cnt_cctv = get_cctv_info(&deq, map);
    visible_area_chk(deq, map, &max);
    cout << m*n << ' ' << cnt_cctv << ' ' << max << " \n";
    cout << m * n - cnt_cctv - max;
}

int get_cctv_info(deque<c_cctv_info> *p_deq, int map[][9])
{
    c_cctv_info cctv_info;
    int cnt = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if (map[i][j] >= 1 && map[i][j] <= 5)
            {
                cctv_info.x = j;
                cctv_info.y = i;
                cctv_info.type = map[i][j];
                cnt++;
                p_deq->push_back(cctv_info);
            }
        }
    }
    return (cnt);
}

int visible_area_chk(deque<c_cctv_info> deq, int map[][9], int *p_max)
{
    if(deq.empty())
    {
        int area = chk_area(map);
        if (*p_max < area)
        {
            *p_max = area;
            // for(int i = 1; i <= n; i++)
            // {
            //     for(int j = 1; j <= m; j++)
            //     {
            //         cout << map[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
        }
        return (*p_max);
    }

    if (deq.front().type == 1)
    {
        int x = deq.front().x;
        int y = deq.front().y;
        deq.pop_front();
        for(int i = 0; i < 4; i++)
        {
            cctv_1(i, p_max, map, x, y, 7);
            visible_area_chk(deq, map, p_max);
            cctv_1(i, p_max, map, x, y, 0);
        }
    }
    else if (deq.front().type == 2)
    {
        int x = deq.front().x;
        int y = deq.front().y;
        deq.pop_front();
        for(int i = 0; i < 2; i++)
        {
            cctv_2(i, p_max, map, x, y, 7);
            visible_area_chk(deq, map, p_max);
            cctv_2(i, p_max, map, x, y, 0);
        }
    }
    else if (deq.front().type == 3)
    {
        int x = deq.front().x;
        int y = deq.front().y;
        deq.pop_front();
        for(int i = 0; i < 4; i++)
        {
            cctv_3(i, p_max, map, x, y, 7);
            visible_area_chk(deq, map, p_max);
            cctv_3(i, p_max, map, x, y, 0);
        }
    }
    else if (deq.front().type == 4)
    {
        int x = deq.front().x;
        int y = deq.front().y;
        deq.pop_front();
        for(int i = 0; i < 4; i++)
        {
            cctv_4(i, p_max, map, x, y, 7);
            visible_area_chk(deq, map, p_max);
            cctv_4(i, p_max, map, x, y, 0);
        }
    }
    else if (deq.front().type == 5)
    {
        int x = deq.front().x;
        int y = deq.front().y;
        deq.pop_front();
        cctv_5(p_max, map, x, y, 7);
        visible_area_chk(deq, map, p_max);
        cctv_5(p_max, map, x, y, 0);
    }
    return (0);
}

int chk_area(int map[][9])
{
    int cnt_visible = 0;
    int cnt_wall = 0;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(map[i][j] == 7)
                cnt_visible++;
            else if(map[i][j] == 6)
                cnt_wall++;
        }
    }
    return (cnt_visible + cnt_wall);
}

void cctv_1(int dir, int *p_max, int map[][9], int x, int y, int ch)
{
    if(dir == 0)
    {
        right_fill(x, y, map, p_max, ch);
    }
    else if(dir == 1)
    {
        left_fill(x, y, map, p_max, ch);
    }
    else if(dir == 2)
    {
        up_fill(x, y, map, p_max, ch);
    }
    else if(dir == 3)
    {
        down_fill(x, y, map, p_max, ch);
    }
}
void cctv_2(int dir, int *p_max, int map[][9], int x, int y, int ch)
{
    if(dir == 0)
    {
        right_fill(x, y, map, p_max, ch);
        left_fill(x, y, map, p_max, ch);
    }
    else if(dir == 1)
    {
        up_fill(x, y, map, p_max, ch);
        down_fill(x, y, map, p_max, ch);
    }
}
void cctv_3(int dir, int *p_max, int map[][9], int x, int y, int ch)
{
    if(dir == 0)
    {
        up_fill(x, y, map, p_max, ch);
        right_fill(x, y, map, p_max, ch);
    }
    else if(dir == 1)
    {
        up_fill(x, y, map, p_max, ch);
        left_fill(x, y, map, p_max, ch);
    }
    else if(dir == 2)
    {
        left_fill(x, y, map, p_max, ch);
        down_fill(x, y, map, p_max, ch);
    }
    else if(dir == 3)
    {
        down_fill(x, y, map, p_max, ch);
        right_fill(x, y, map, p_max, ch);
    }
}
void cctv_4(int dir, int *p_max, int map[][9], int x, int y, int ch)
{
    if(dir == 0)
    {
        up_fill(x, y, map, p_max, ch);
        left_fill(x, y, map, p_max, ch);
        right_fill(x, y, map, p_max, ch);
    }
    else if(dir == 1)
    {
        up_fill(x, y, map, p_max, ch);
        down_fill(x, y, map, p_max, ch);
        left_fill(x, y, map, p_max, ch);
    }
    else if(dir == 2)
    {
        down_fill(x, y, map, p_max, ch);
        left_fill(x, y, map, p_max, ch);
        right_fill(x, y, map, p_max, ch);
    }
    else if(dir == 3)
    {
        up_fill(x, y, map, p_max, ch);
        down_fill(x, y, map, p_max, ch);
        right_fill(x, y, map, p_max, ch);
    }
}
void cctv_5(int *p_max, int map[][9], int x, int y, int ch)
{
    up_fill(x, y, map, p_max, ch);
    down_fill(x, y, map, p_max, ch);
    left_fill(x, y, map, p_max, ch);
    right_fill(x, y, map, p_max, ch);
}

void right_fill(int x, int y, int map[][9], int *p_max, int ch)
{
     // right
    // cout << x << ',' << y << ',' << ch << "right\n" ;
    while(x <= m && map[y][x] != 6)
    {
        if(map[y][x] >= 1 && map[y][x] <= 5)
        {
            x++;
            continue;
        }
        map[y][x++] = ch;
    }
}

void left_fill(int x, int y, int map[][9], int *p_max, int ch)
{
    // left
    // cout << x << ',' << y << ',' << ch << "left\n" ;
    while(x >= 1 && map[y][x] != 6)
    {
        if(map[y][x] >= 1 && map[y][x] <= 5)
        {
            x--;
            continue;
        }
        map[y][x--] = ch;
    }
}

void up_fill(int x, int y, int map[][9], int *p_max, int ch)
{
    // up
    // cout << x << ',' << y << ',' << ch << "up\n" ;
    while(y >= 1 && map[y][x] != 6)
    {
        if(map[y][x] >= 1 && map[y][x] <= 5)
        {
            y--;
            continue;
        }
        map[y--][x] = ch;
    }
}

void down_fill(int x, int y, int map[][9], int *p_max, int ch)
{
    // down
    // cout << x << ',' << y << ',' << ch << "down\n" ;
    while(y <= n && map[y][x] != 6)
    {
        if(map[y][x] >= 1 && map[y][x] <= 5)
        {
            y++;
            continue;
        }
        map[y++][x] = 7;
    }
}