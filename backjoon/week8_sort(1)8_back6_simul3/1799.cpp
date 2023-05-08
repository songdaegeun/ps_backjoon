#include <iostream>
#include <algorithm>
using namespace std;

int map[2][11][11];
int visited1[21];
int visited2[21];

int n;
int ans[2];



int stop_flag = 0;
void solve(int x, int y, int cnt, int color)
{
	if(x >= n)
	{
		ans[color] = max(ans[color], cnt);
		return ;
	}
	else if(y >= n)
	{
		x++;
		if(y % 2 == 0) y = 1;
		else y = 0;
	}
	if(map[color][x][y] && !visited1[x + y] && !visited2[x - y + n - 1])
	{
		visited1[x + y] = 1;
		visited2[x - y + n - 1] = 1;
		solve(x, y + 2, cnt + 1, color);
		visited1[x + y] = 0;
		visited2[x - y + n - 1] = 0;
	}
	solve(x, y + 2, cnt, color);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[(i + j) % 2][i][j];
		}
	}
	// 1. 1인 공간의 루프를 돌며 최대 7개까지 한 개씩 착수하면서 백트래킹.
	// 7개를 착수했거나, 아무데도 착수 할 곳이 없다면 종료.  -- o
	// 2. 1인 공간에서 1~7개를 선택하고 착수 가능한지 판단.
	// 선택한 개수의 모든 조합에서 모두 착수 불가능하다면 종료.  -- x
	// 3. 격자로 나눠서 2영역으로 생각. 
	solve(0, 0, 0, 0);
	solve(0, 1, 0, 1);
	
	// 최대 7개의 착수 가능한 비숍을 출력.
	cout << ans[0] + ans[1];
}

// 5
// 1 1 0 1 1
// 0 1 0 0 0
// 1 0 1 0 1
// 1 0 0 0 0
// 1 0 1 1 1

// 10
// 1 1 0 1 1 1 1 0 1 1
// 0 1 0 0 0 0 1 0 0 0
// 0 0 0 0 1 0 0 0 0 1
// 1 0 0 0 0 1 0 0 0 0
// 1 0 1 0 1 1 0 1 0 1
// 1 1 0 1 1 1 1 0 1 1
// 0 1 0 0 0 0 1 0 0 0
// 0 0 0 0 1 0 0 0 0 1
// 1 0 0 0 0 1 0 0 0 0
// 1 0 1 0 1 1 0 1 0 1

// 10
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 0 1 1 1 1 0 1 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1 1 1 1

