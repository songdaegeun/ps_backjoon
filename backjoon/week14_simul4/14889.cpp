#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int s[21][21];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s[i][j];
		}
	}
	// N명 중 N/2명을 선택.
	// ex. 2,3,4가 팀일 경우,
	// 2, 3 / 2, 4 / 3, 2 / 3, 4 / 4, 2 / 4, 3 쌍의 총합이 stat1
	// stat1 += s[i][j] + s[j][i];
	vector<int> v(n, 0);
	for (int i = n / 2; i < n; i++)
		v[i] = 1;
	int min = 1000;
	do
	{
		int stat1, stat2;
		stat1 = 0;
		stat2 = 0;
		vector<int> member1;
		vector<int> member2;
		for (int i = 0; i < n; i++)
		{
			if(v[i] == 1)
				member1.push_back(i);
			else
				member2.push_back(i);
		}
		for (int i = 0; i < member1.size(); i++)
		{
			for (int j = 0; j < member1.size(); j++)
			{
				stat1 += s[member1[i]][member1[j]];
			}
		}
		for (int i = 0; i < member2.size(); i++)
		{
			for (int j = 0; j < member2.size(); j++)
			{
				stat2 += s[member2[i]][member2[j]];
			}
		}
		if(min > abs(stat1 - stat2))
			min = abs(stat1 - stat2);
	} while (next_permutation(v.begin(), v.end()));
	
	cout << min << '\n';
}

// 4
// 0 1 2 3
// 4 0 5 6
// 7 1 0 2
// 3 4 5 0