#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
char map[101][101];
int visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int oob(int x, int y){
    return (x < 0 || x >= n || y < 0 || y >= n);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> q;
    string str;

    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, str);
        for(int j = 0; j < n; j++){
            map[i][j] = str[j];
        }
    }
    memset(visited, 0, sizeof(int) * 101 * 101);
    int cnt1 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (visited[i][j] == 0)
            {
                visited[i][j] = 1;
                q.push({i, j});
                cnt1++;
                while(!q.empty()){
                    pair<int, int> pos = q.front(); 
                    q.pop();
					int x = pos.first;
					int y = pos.second;
                    for(int i = 0; i < 4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(oob(nx, ny)) continue;
                        if(visited[nx][ny] || (map[x][y] != map[nx][ny])) continue;
						visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    memset(visited, 0, sizeof(int) * 101 * 101);
    int cnt2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (visited[i][j] == 0)
            {
                visited[i][j] = 1;
                q.push({i, j});
                cnt2++;
                while(!q.empty()){
                    pair<int, int> pos = q.front(); 
                    q.pop();
					int x = pos.first;
					int y = pos.second;
					if (map[x][y] == 'G')
							map[x][y] = 'R';
                    for(int i = 0; i < 4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
						if (map[nx][ny] == 'G')
							map[nx][ny] = 'R';
                        if(oob(nx, ny)) continue;
                        if(visited[nx][ny] || (map[x][y] != map[nx][ny])) continue;
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
	cout << cnt1 << ' ' << cnt2;

}
// 5
// RRRBB
// GGBBB
// BBBRR
// BBRRR
// RRRRR