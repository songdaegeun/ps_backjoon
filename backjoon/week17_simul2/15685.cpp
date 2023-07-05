#include <iostream>
#include <vector>
using namespace std;

int map[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        // map에 dragon curve draw
        vector<int> v;
        map[y][x] = 1;
        v.push_back(d);
        
        while(g--) {
            // generation up
            int v_size = v.size();
            for (int j = (v_size - 1); j >= 0; j--)
            {
                v.push_back((v[j]+1)%4);
            }
        }
        
        for(auto el:v) {
            if(el == 0) x++;
            else if(el == 1) y--;
            else if(el == 2) x--;
            else if(el == 3) y++;
            map[y][x] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1]) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}

//  K(K > 1)세대 드래곤 커브는 K-1세대 드래곤 커브를 끝 점을 기준으로 90도 시계 방향 회전 시킨 다음, 그것을 끝 점에 붙인 것이다.

// 3
// 3 3 0 1
// 4 2 1 3
// 4 2 2 1