#include <iostream>
#include <vector>
using namespace std;

int r, c, k;
int arr[101][101];

int cmp(pair<int,int> a, pair<int,int> b)
{
	if(a.first != b.first)
		return (a.first < b.first);
	else
		return (a.second < b.second);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	int row_size = 3;
	int col_size = 3;
	int t = 0;
	while(t <= 100)
	{
		if (arr[r][c] == k) {
			cout << t << '\n';
			return (0);
		}
		// arr에 연산적용
		if(row_size >= col_size) {
			// r연산
			for (int i = 1; i <= row_size; i++)
			{
				// i행에 대해 대해 정렬
				// 1~col_size열에 등장한 수를 cnt
				vector<pair<int,int>> re_arrange;
				int cnt[101];
				memset(cnt, 0, sizeof(cnt));
				// 3, 1, 1
				for (int j = 1; j <= col_size; j++) {
					cnt[arr[i][j]]++;
				}
				// arr내의 수는 1~100
				for (int j = 1; j <= 100; j++) {
					if(cnt[j] != 0) {
						re_arrange.push_back({cnt[j], j});
					}
				}
				// re_arrange.first 기준으로 idx를 정렬
				sort(re_arrange.begin(), re_arrange.end(), cmp);
				// 수, 등장횟수를 arr에 대입
				for (int j = 0; j < 2 * re_arrange.size(); j+=2)
				{
					arr[i][1 + j] = re_arrange[j].second;
					arr[i][1 + j + 1] = re_arrange[j + 1].first;
				}
			}
		}
		else {
			// c연산

		}
		t++;
	}
	cout << -1 << '\n';
	return (0);
}

// A[r][c]에 들어있는 값이 k가 되기 위한 연산의 최소 시간을 출력한다. 100초가 지나도 A[r][c] = k가 되지 않으면 -1을 출력한다.

// R 연산: 배열 A의 모든 행에 대해서 정렬을 수행한다. 행의 개수 ≥ 열의 개수인 경우에 적용된다.
// C 연산: 배열 A의 모든 열에 대해서 정렬을 수행한다. 행의 개수 < 열의 개수인 경우에 적용된다.
// 예를 들어, [3, 1, 1]에는 3이 1번, 1가 2번 등장한다.
// 따라서, 정렬된 결과는 [3, 1, 1, 2]가 된다. 다시 이 배열에는 3이 1번, 1이 2번, 2가 1번 등장한다.
// 다시 정렬하면 [2, 1, 3, 1, 1, 2]가 된다.

// 정렬된 결과를 배열에 다시 넣으면 행 또는 열의 크기가 달라질 수 있다. R 연산이 적용된 경우에는 가장 큰 행을 기준으로 모든 행의 크기가 변하고,
// C 연산이 적용된 경우에는 가장 큰 열을 기준으로 모든 열의 크기가 변한다.
// 행 또는 열의 크기가 커진 곳에는 0이 채워진다. 수를 정렬할 때 0은 무시해야 한다.
// 예를 들어, [3, 2, 0, 0]을 정렬한 결과는 [3, 2]를 정렬한 결과와 같다.
// 행 또는 열의 크기가 100을 넘어가는 경우에는 처음 100개를 제외한 나머지는 버린다.



// 1 2 2
// 1 2 1
// 2 1 3
// 3 3 3