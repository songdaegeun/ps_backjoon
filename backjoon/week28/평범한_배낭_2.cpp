// 평범한_배낭_2
// 최대 무게 m에 대해 물건을 중복가능하게 선택하여 얻을 수 있는 최대가치?

#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<pair<int,int>> v_c; // 무게, 가치
int dp[2001][10001];

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		int v,c,k;
		cin >> v >> c >> k;

		// 2진수로 쪼개서 저장. 이 요소들의 조합으로 1~k까지 표현이 가능하다!!
		// O(n*log(k)*m)
		for(int i=k; i>=1; i = i>>1) {
			int part = i - (i>>1);
			v_c.push_back({v*part,c*part});	
		}
		// O(n*k*m)이라서 시간초과.
		// while(k--) {
		// 	v_c.push_back({v,c});	
		// }
	}
	for(int i=0; i<=n; i++) {
		dp[i][0] = 0;
	}
	for(int i=0; i<=m; i++) {
		dp[0][i] = 0;
	}

	for(int j=1; j<=m; j++) {
		for(int i=1; i<=v_c.size(); i++) {
			if(j-v_c[i-1].first < 0) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-v_c[i-1].first]+v_c[i-1].second);
			}
		}
	}
	cout << dp[v_c.size()][m] << '\n';
}


// 2 3
// 2 7 1
// 1 9 3