#include <iostream>
using namespace std;

int queen[16];
int is_used1[16];
int is_used2[32];
int is_used3[32];

int n;
int cnt;

int can_set(int y, int x)
{
    for (int prev_y = 0; prev_y < y; prev_y++)
    {
        int prev_x = queen[prev_y];
        if ((x - prev_x) == (y - prev_y))
            return (0);
        else if((x - prev_x) == -1 * (y - prev_y))
            return (0);
        else if(x == prev_x)
            return (0);
    }
    return (1);
}

void queen_set(int y)
{
    if(y == n)
    {
        cnt++;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << queen[i] << ' ';
        // }
        // cout << '\n';
        
        return ;
    }

    for (int x = 0; x < n; x++)
    {
        if(is_used1[x] ||  is_used2[x + y] ||  is_used3[x - y + n - 1]) continue;
        is_used1[x] = 1;
        is_used2[x + y] = 1;
        is_used3[x - y + n - 1] = 1;
        queen[y] = x;
        queen_set(y + 1);
        is_used1[x] = 0;
        is_used2[x + y] = 0;
        is_used3[x - y + n - 1] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> n;
    queen_set(0);    
    cout << cnt;
}
// 8