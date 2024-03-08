// 평범한 배낭

#include <iostream>
using namespace std;

// 한 줄에 배낭에 넣을 수 있는 물건들의 가치합의 최댓값을 출력한다.
// dp[i][j] : 물건을 i개까지 고려했을 때, 최대무게 j에 대해 담을 수 있는 최대 가치.

int dp[101][100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	int w[101] = {};
	int v[101] = {};
	
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> w[i] >> v[i];
	}
	
	for(int i=0; i<=n; i++) {
		dp[i][0] = 0;
	}
	for(int i=0; i<=k; i++) {
		dp[0][i] = 0;
	}

	for(int j=1; j<=k; j++) {
		for(int i=1; i<=n; i++) {
			if(w[i] > j) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
			}
		}
	}
	cout << dp[n][k] << '\n';
}

// 4 7
// 6 13
// 4 8
// 3 6
// 5 12