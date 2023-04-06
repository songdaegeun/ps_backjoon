#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;

int oob(int x, int y)
{
    return (x < 0 || x >= n|| y < 0 || y >= m);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int map[501][501];
    int visit[501][501];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    cin >> n >> m;
    
}