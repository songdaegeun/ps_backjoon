#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char chosen_oper[12];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n = 3;

	for (int i = 0; i < n - 1; i++)
	{
		chosen_oper[i] = i + '0';
	}
	do
	{
		for (int i = 0; i < n - 1; i++)
			cout << chosen_oper[i] << ' ';
		cout << '\n';
		
	} while (next_permutation(chosen_oper, chosen_oper + 2));
}
// N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.

// 첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 
// 셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다.

// 2
// 5 6
// 0 0 1 0