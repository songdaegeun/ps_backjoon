#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[12];
int oper[4];	// +, -, *, /
char chosen_oper[12];

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
	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}
	// n-1개 중에서 n-1개를 순서고려하여 선택한다.
	// 같은 case가 중복되는 것을 허용할 경우, 시간복잡도: O(n-1^n-1)이지만 n-1Pn-1 -> 3,628,800(n = 11) ok.
	// 같은 case가 중복되는 것을 허용하지 않는경우, n-1P4 / (2이상인 각 연산자의 개수) ->O(n-1^4) -> 10000(n = 11) ok.
	
	int idx = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < oper[i]; j++)
		{
			if(i == 0)
				chosen_oper[idx++] = '+';
			else if(i == 1)
				chosen_oper[idx++] = '-';
			else if(i == 2)
				chosen_oper[idx++] = '*';
			else if(i == 3)
				chosen_oper[idx++] = '/';
		}
	}
	sort(chosen_oper, chosen_oper + n - 1);
	int max = -1000000000;
	int min = 1000000000;
	do
	{
		int res = arr[0];
		for (int i = 0; i < n - 1; i++)
		{
			if(chosen_oper[i] == '+')
				res = res + arr[i + 1];
			else if(chosen_oper[i] == '-')
				res = res - arr[i + 1];
			else if(chosen_oper[i] == '*')
				res = res * arr[i + 1];
			else if(chosen_oper[i] == '/')
				res = res / arr[i + 1];
		}
		if(max < res)
			max = res;
		if(min > res)
			min = res;
	} while (next_permutation(chosen_oper, chosen_oper + n - 1));
	cout << max << '\n' << min << '\n';
}
// N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.

// 첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 
// 셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다.

// 2
// 5 6
// 0 0 1 0