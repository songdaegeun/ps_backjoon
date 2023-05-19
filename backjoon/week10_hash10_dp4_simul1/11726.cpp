#include <iostream>
using namespace std;

int d[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int m;
	cin >> m;
	// 2 x m 의 map에 대해 1×2, 2×1 타일로 채우는 모든 경우의 수를 10,007로 나눈 나머지를 출력한다
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= m; i++)
	{
		d[i] =(d[i - 1] + d[i - 2]) % 10007;  // 더하기니까 가능.
	}
	cout << d[m] << '\n';
}

// 2