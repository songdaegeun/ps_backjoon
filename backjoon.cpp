#include <iostream>
using namespace std;

int tc, n, m;

void disp_map(string map[101])
{
    cout << '\n';
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> tc;
    while(tc--)
    {
        cin >> n >> m;
        string map[101];
        string keys;
        for (int i = 0; i < n; i++)
        {
            cin >> map[i];
        }
        cin >> keys;
        disp_map(map);
    }

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