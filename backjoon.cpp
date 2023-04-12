#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
char map[1000][1000];
int j_dist[1000][1000];
int f_dist[1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int oob(int x, int y)
{
    return (x < 0 || x >= n|| y < 0 || y >= m);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	
	
}
