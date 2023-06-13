#include <iostream>
using namespace std;

int arr[100001];
int d[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> x;
	// ai + aj = x를 만족하는 쌍의 수를 출력하라.
	// arr를 순회하면서 dp table에 현재 요소가 존재한다면 해당 요소는 조건식을 만족하는 쌍을 구성함.
	// arr를 순회하면서 각 요소에 대해 더해져야하는 값을 dp table에 메모.
	// O(N)가능.
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if(d[arr[i]] == 1) cnt++;
		if(x - arr[i] >= 0)
			d[x - arr[i]] = 1;
	}
	cout << cnt << '\n';
}