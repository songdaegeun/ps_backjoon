#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int n, m;
int map[1002][1002];
int dist[1002][1002][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void disp_map();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	
}

// 6 4
// 0100
// 1110
// 1000
// 0000
// 0111
// 0000

void disp_map()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}