#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a_vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	int temp_n;
	temp_n = n;
	// a,b[n]의 순열의 모든 경우에 대해, 총합을 구해보고 최대값을 출력한다.
	int a_val, b_val;
	long long b_sum = 0;
	while (temp_n--)
	{
		cin >> a_val >> b_val;
		b_sum += b_val;
		a_vec.push_back(a_val);
	}
	sort(a_vec.begin(), a_vec.end(), greater<int>());

	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (long long)a_vec[i]*(n-i);
	}
	sum += b_sum;
	
	cout << sum << '\n';
}

// 각각의 함수에 1부터 n까지를 더해서 만들 수 있는 최대값을 구한다.

// 5
// 2 4
// 5 1
// 3 2
// 1 10
// 0 0