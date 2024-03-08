#include <iostream>
#include <limits.h>
using namespace std;

// 합이 n과 같게 되는 제곱수들의 최소 개수.
int dp[50001]; 
int n;

int is_powered(int n) {
	int i = 1;
	while(i<= n/i) {
		if(i*i == n)
			return (true);
		i++;
	}
	return (false);
}

int main() {
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;	
	// dp[i] = min(dp[i-1] + dp[i-4] + dp[i-9] + dp[i-25] ..) + 1;
	
	for(int i=2; i<=n; i++) {
		int min_val = INT_MAX;
		for(int j=1; j*j<=i; j++) {
			min_val = min(min_val, dp[i-j*j]);
		}
		dp[i] = min_val+1;
	}
	cout << dp[n] << '\n';
}

// 25 -> 1 
// 26 -> 2