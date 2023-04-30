#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int map[51][51];
int visited[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int oob(int x, int y){
    return (x < 0 || x >= n || y < 0 || y >= m);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> q;
    int k, bae_num;
    int x, y;
    cin >> k;
    while(k--){
        memset(map, 0, sizeof(int) * 51 * 51);
        memset(visited, 0, sizeof(int) * 51 * 51);
        cin >> m >> n >> bae_num;
        while(bae_num--){
            cin >> y >> x;
            map[x][y] = 1;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (map[i][j] == 1 && visited[i][j] == 0)
                {
                    visited[i][j] = 1;
                    q.push({i, j});
                    cnt++;
                    while(!q.empty()){
                        pair<int, int> pos = q.front(); 
                        q.pop();
                        for(int i = 0; i < 4; i++){
                            int nx = pos.first + dx[i];
                            int ny = pos.second + dy[i];
                            if(oob(nx, ny)) continue;
                            if(visited[nx][ny] || map[nx][ny] == 0) continue;
                            visited[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
    

}

// 2
// 10 8 17
// 0 0
// 1 0
// 1 1
// 4 2
// 4 3
// 4 5
// 2 4
// 3 4
// 7 4
// 8 4
// 9 4
// 7 5
// 8 5
// 9 5
// 7 6
// 8 6
// 9 6
// 10 10 1
// 5 5