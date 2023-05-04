#include <iostream>
#include <algorithm>
using namespace std;

int n;
// int arr[10000001];
// arr의 요소의 범위가 대략 1000만 이하일 때만 쓸 수 있다.
int tmp[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		tmp[num]++;
	}
	// sort(arr, arr + n, less<int>());

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < tmp[i]; j++)
		{
			cout << i << '\n';
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