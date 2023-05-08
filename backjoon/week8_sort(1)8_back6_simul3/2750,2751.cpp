#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, less<int>());

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
}

// 5
// 5
// 4
// 3
// 2
// 1