#include <iostream>
using namespace std;

int step[301];
pair<int,int> d[301];	// score, 인접계단방문여부.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> step[i];
	}
	d[1] = make_pair(step[1], 0);
	d[2] = make_pair(step[1] + step[2], 1);
	for (int i = 3; i <= n; i++)
	{
		if (d[i - 1].second)	// 직전 인접계단을 방문했다면
		{
			d[i].first = d[i - 2].first + step[i];
			d[i].second = 0;
		}
		else
		{
			if(i <= n - 2)
			{
				int cmp[3];

				cmp[0] = d[i - 1].first + step[i + 2];
				cmp[1] = d[i - 2].first + step[i + 1];
				cmp[2] = d[i - 2].first + step[i + 2];
			
				int max_idx = 0;
				for (int j = 1; j < 3; j++)
				{
					if(cmp[max_idx] < cmp[j]) max_idx = j;
				}
				if(max_idx == 0)
				{
					d[i].first = d[i - 1].first + step[i];
					d[i].second = 1;
				}
				else
				{
					d[i].first = d[i - 2].first + step[i];
					d[i].second = 0;
				}
			}
			else if(i == n - 1)
			{
				// 직전 계단을 선택하면 마지막 계단을 갈수 없다.
				d[i].first = d[i - 2].first + step[i];
				d[i].second = 0;

			}
			else
			{
				d[i].first = max(d[i - 1].first, d[i - 2].first) + step[i];
			}
		}
	}

	cout << d[n].first << '\n';
}

// 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
// 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
// 마지막 도착 계단은 반드시 밟아야 한다.

// 총 점수의 최댓값 출력.

// 6
// 10
// 20
// 15
// 25
// 10
// 20