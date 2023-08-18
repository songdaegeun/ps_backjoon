#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int sol(vector<int> &coin, int total) {
	int dp[10001];
	int n = coin.size();
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j <= total; j++)
		{
			dp[j] += dp[j - coin[i]];
		}
	}
	return (dp[total]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int t;
	cin >> t;
	while(t--) {
		int n, total;
		cin >> n;
		vector<int> coin;
		while(n--) {
			
			int c;
			cin >> c;
			coin.push_back(c);
		}
		cin >> total;
		cout << sol(coin, total) << '\n';
	}
	return (0);
}

// 1
// 2
// 1 2
// 1000

// 3
// 2
// 1 2
// 1000
// 3
// 1 5 10
// 100
// 2
// 5 7
// 22