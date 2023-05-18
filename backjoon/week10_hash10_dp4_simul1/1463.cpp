#include <iostream>
using namespace std;

int d[1000001];

int sol(int n) {
	d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if(i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
		if(i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
	}
	return  d[n];
}
	

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
	cout << sol(n);
}

// X가 3으로 나누어 떨어지면, 3으로 나눈다.
// X가 2로 나누어 떨어지면, 2로 나눈다.    
// 1을 뺀다.                         

// 1을 만들기위한 연산 횟수의 최솟값 출력.