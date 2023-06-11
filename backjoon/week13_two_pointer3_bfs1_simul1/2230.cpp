#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int min = 2147483647;
	int en = 0;
	for (int st = 0; st < n; st++)
	{
		while (en < n && arr[en] - arr[st] < m) en++;
		if(en == n) continue;
		if (min > (arr[en] - arr[st]))
			min = arr[en] - arr[st];
	}
	cout << min << '\n';
}
// 10,000,000,000
// 3 3 3 3 3 3 3 7

// 3 3
// 1
// 5
// 3