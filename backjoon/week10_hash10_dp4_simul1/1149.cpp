#include <iostream>
// #include <algorithm>
using namespace std;

int cost[1001][1001];
int d[1001][4];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> cost[i][j];
		}
	}
	// 인접한 집간의 색이 같으면 안된다.
	// n번 집을 칠하는 비용의 최소값을 구해야한다.
	// d[n][3] = min(d[n - 1][1],d[n - 1][2]) + cost[n][3];
	// d[n][2] = min(d[n - 1][1],d[n - 1][3]) + cost[n][2];
	// d[n][1] = min(d[n - 1][2],d[n - 1][3]) + cost[n][1];
	d[1][1] = cost[1][1];
	d[1][2] = cost[1][2];
	d[1][3] = cost[1][3];
	for (int i = 2; i <= n; i++)
	{
		d[i][3] = min(d[i - 1][1], d[i - 1][2]) + cost[i][3];
		d[i][2] = min(d[i - 1][1], d[i - 1][3]) + cost[i][2];
		d[i][1] = min(d[i - 1][2], d[i - 1][3]) + cost[i][1];
	}
	// int min = 100000;

	// if(min > d[n][1])
	// 	min = d[n][1];
	// if(min > d[n][2])
	// 	min = d[n][2];
	// if(min > d[n][3])
	// 	min = d[n][3];

	// cout << min << '\n';
	// cout << *min_element(d[n] + 1, d[n] + 4) << '\n';
	cout << min({d[n][1], d[n][2], d[n][3]}) << '\n';
}
// 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
// N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
// i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

// 모든 집을 칠하는 비용의 최솟값 출력.

// R G B
// 3
// 26 40 83
// 49 60 57
// 13 89 99