#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int tc, n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int sol;

void disp_map(char map[101][101])
{
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int has_key(char ch, vector<char> &keys)
{
    int diff = 'a' - 'A';

    for (auto el: keys)
    {
        if((el - diff) == ch)
            return (1);
    }
    return (0);
}

int is_gate(char ch)
{
    if('A' <= ch && ch <= 'Z')
        return (1);
    else 
        return (0);
}

int bound_entry(char map[101][101], int i, int j, vector<char> &keys)
{
    if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
    {
        if(map[i][j] == '*')
            return (0);
        if(is_gate(map[i][j]))
        {
            if(has_key(map[i][j], keys))
                return (1);
            else
                return (0);
        }
        else
        {
            // '.' key '$'
            if(map[i][j] == '$')
               sol++;
            else if(map[i][j] == '.')
                ;
            else
                keys.push_back(map[i][j]);
            return (1);
        }
    }
    return (0);
}

int bsq(char map[][101], vector<pair<int,int>> &entry, vector<char> &keys)
{
    disp_map(map);
    queue<pair<int,int>> q;
    int visited[101][101];
    memset(visited, 0, sizeof(int) * 101 * 101);
    int cnt = 0;
    for (auto el:entry)
    {
        visited[el.first][el.second] = 1;
        q.push({el.first, el.second});
    }
    while(!q.empty())
    {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        cout << x << ' ' << y << '\n';
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] == '*' || visited[nx][ny]) continue;            
            if(is_gate(map[nx][ny]) && !has_key(map[nx][ny], keys))
            {
                // 덜탐색한 곳이 있으면 nx, ny push.
                // 모두 탐색했으면 continue;
                
                continue;
            }
            if(!is_gate(map[nx][ny]) && map[nx][ny] != '.')
            {
                if(map[nx][ny] == '$')
                    cnt++;
                else
                    keys.push_back(map[nx][ny]);
            }
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return (cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        char map[101][101];
        vector<char> keys;
        vector<pair<int,int>> entry;
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < m; j++)
            {
                map[i][j] = tmp[j];
            }
        }
        cin.ignore();
        string tmp;
        getline(cin, tmp);
        if(tmp != "0")
        {
            for(auto ch: tmp)
                keys.push_back(ch);
        }
        sol = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(bound_entry(map, i, j, keys))
                    entry.push_back({i, j});
            }
        }
        cout << sol + bsq(map, entry, keys) << '\n';
    }
    // 모든 입구를 queue에 넣는다.
    // 키에 해당하는 문은 통과한다.
    // 키를 획득하면 keys에 추가한다.

}

// 3
// 5 17
// *****************
// .............**$*
// *B*A*P*C**X*Y*.X.
// *y*x*a*p**$*$**$*
// *****************
// cz
// 5 11
// *.*********
// *...*...*x*
// *X*.*.*.*.*
// *$*...*...*
// ***********
// 0
// 7 7
// *ABCDE*
// X.....F
// W.$$$.G
// V.$$$.H
// U.$$$.J
// T.....K
// *SQPML*
// irony