#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[100001];

long long reverse(long long num) {
	long long rev = 0;
	int rev_arr[12];

	int digit_num = 0;
	while(num) {
		rev_arr[digit_num] = num % 10;
		num /= 10;
		digit_num++;
	}

	for (int i = 0; i < digit_num; i++)
	{
		rev *= 10;
		rev += rev_arr[i];
	}
	return (rev);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	// arr를 순회하며 모든 요소를 뒤집는다.
	for (int i = 0; i < n; i++)
	{
		arr[i] = reverse(arr[i]);
	}
	// 이 후 정렬한다.
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}
}

// 10 5 2233
// 1601 90100 13009 802
// 50000000
// 301 7654321
// 210