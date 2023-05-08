#include <iostream>
#include <algorithm>
using namespace std;

int n;
// arr의 요소의 범위가 대략 1000만 이하일 때만 쓸 수 있다.
int tmp[2000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		tmp[num + 1000000]++;
	}

	for (int i = 2000000; i >= 0; i--)
	{
		for (int j = 0; j < tmp[i]; j++)
		{
			cout << i - 1000000 << '\n';
		}
	}
}

// 10
// 5
// 2
// 3
// 1
// 4
// 2
// 3
// 5
// 1
// 7