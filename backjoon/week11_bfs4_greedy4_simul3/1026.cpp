#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[51];
int b[51];
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a, a+n);
	sort(b, b+n, greater<int>());

	for (int i = 0; i < n; i++)
		ans += a[i]*b[i];
	cout << ans << '\n';
}

// a: 3 2 1 1
// b: 1 2 3 4

// a: 1 1 2 3
// b: 1 2 4 3

// a[i]에 대해 큰 숫자는 최대한 적게 곱해져야한다. 
// b[i]의 크기에 역순으로 재배열하면 된다.

// S = A[0] × B[0] + ... + A[N-1] × B[N-1]
// S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안 된다.
// S의 최솟값을 출력하는 프로그램을 작성하시오.

// 5
// 1 1 1 6 0
// 2 7 8 3 1
