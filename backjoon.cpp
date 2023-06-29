#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,h;
int map[31][31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> h;
    // h x n 격자에 m개의 가로선을 놓을 수 있다.
    // 가로선이 놓일 수 있는 위치는 1,1 - h,n-1 중에 map[i][j] != 1 && map[i][j+1] != 1인 위치
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }

    vector<pair<int,int>> pos;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if((j == 1 || map[i][j-1] != 1) && (map[i][j+1] != 1) && map[i][j] != 1) {
                pos.push_back({i,j});
            }
        }
    }
    for(int k = 0; k <= 3; k++) {
        vector<int> mask(pos.size(),0);
        for (int i = pos.size() - k; i < pos.size(); i++)
            mask[i] = 1;    
        do
        {
            for (int i = 0; i < pos.size(); i++)
            {
                if(mask[i]) {
                    map[pos[i].first][pos[i].second] = 1;
                }
            }
            // simulation
            // 세로 x, 가로 y 
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                int x = 1; 
                int y = j;
                while(1) {
                    if(map[x][y] == 1 || (y-1 >= 1 && map[x][y-1])) {
                        if(y-1 >= 1 && map[x][y-1]) {
                            y--;
                        }
                        else {
                            y++;
                        }
                        x++;
                    }
                    else {
                        x++;
                    }
                    if(x == (h + 1)) {
                        if(y == j) {
                            cnt++;
                        }
                        break;
                    }
                }
            }
            // for (int i = 1; i <= h; i++)
            // {
            //     cout << '\n';
            //     for (int j = 1; j <= n; j++)
            //     {
            //         cout << map[i][j] << ' ';
            //     }
            // }
            // cout << '\n';
            if(cnt == n) {
                cout << k << '\n';
                return (0);
            }
            // map복구
            for (int i = 0; i < pos.size(); i++)
            {
                if(mask[i]) {
                    map[pos[i].first][pos[i].second] = 0;
                }
            }
        } while (next_permutation(mask.begin(), mask.end()));
    }
    cout << -1 << '\n';
    return (0);

    // for (int i = 1; i <= h; i++)
    // {
    //     cout << '\n';
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << map[i][j] << ' ';
    //     }
    // }
}

// 5 6 6
// 1 1
// 3 1
// 5 2
// 4 3
// 2 3
// 1 4