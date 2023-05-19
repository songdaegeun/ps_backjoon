#include <iostream>
#include <algorithm>
using namespace std;

int coin[11];
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n, total;
	cin >> n >> total;
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}
	sort(coin, coin + n, greater<int>());
	// coin[1]X1 + coin[2]X2 + ... + coin[n]Xn = total
	// X1 + X2 + ... + Xn = ans
	// total을 구성하는 가중치는 Xn에 가까울수록 큼.
	// 가능한 Xn에 가까운게 많을수록 ans가 작아짐.
	// 이 논리는 total이 변동되는 모든 순간에 적용됨.
	// 즉 total에서 coin[]으로 뺄 수 있는 가장 큰 값을 계속 빼면 됨.
	while(total) {
		int i = 0;
		while(i < n)
		{
			if (total - coin[i] >= 0)
			{
				total -= coin[i];
				ans++;
				break;
			}
			else
				i++;
		}
	}
	cout << ans << '\n';
}
// 필요한 동전 개수의 최솟값 출력.

// 10 4200
// 1
// 5
// 10
// 50
// 100
// 500
// 1000
// 5000
// 10000
// 50000