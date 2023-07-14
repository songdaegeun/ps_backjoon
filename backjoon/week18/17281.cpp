#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
int member_score[51][10];
int base[4];
int ans;
int hit_order[9];


void disp(int (&tmp)[9])
{
	cout << '\n';
	for (int i = 0; i < 9; i++)
	{
		cout << tmp[i] << ' ';
	}
	cout << '\n';
}

int incre_base() {
	int tmp_base[4];

	for (int i = 0; i < 3; i++)
	{
		tmp_base[i] = base[i];
	}
	for (int i = 0; i < 3; i++)
	{
		base[i+1] = tmp_base[i];
	}
	base[0] = 0;
	if(base[3] == 1) {
		base[3] = 0;
		return (1);
	}
	else
		return (0);
}

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> member_score[i][j];
		}
	}
	for (int i = 0; i < 9; i++)
	{
		hit_order[i] = i;
	}
	// 타순의 모든 경우에 대해 total_score계산
	do
	{
		if(hit_order[3] != 0) continue;
		int total_score = 0;
		int k = 0;
		// n이닝 진행
		for (int ening = 0; ening < n; ening++)
		{
			memset(base, 0, sizeof(base));
			int out_cnt = 0;
			// 이닝 시뮬레이션
			while(1)
			{
				switch (member_score[ening][hit_order[k]])
				{
				case 1:
					if(incre_base())
						total_score++;
					base[0] = 1;
					break;
				case 2:
					if(incre_base())
						total_score++;
					if(incre_base())
						total_score++;
					base[1] = 1;
					break;
				case 3:
					if(incre_base())
						total_score++;
					if(incre_base())
						total_score++;
					if(incre_base())
						total_score++;
					base[2] = 1;
					break;
				case 4:
					if(incre_base())
						total_score++;
					if(incre_base())
						total_score++;
					if(incre_base())
						total_score++;
					total_score++;
					break;
				case 0:
					out_cnt++;
					break;
				default:
					break;
				}
				k = (k+1)%9;
				if(out_cnt == 3)
					break;
			}
		}
		if(total_score > ans) {
			ans = total_score;
			// disp(hit_order);
			// cout << ans << '\n';
		} 
	} while (next_permutation(hit_order, hit_order + 9));	
	cout << ans;
}

// 안타: 1
// 2루타: 2
// 3루타: 3
// 홈런: 4
// 아웃: 0

// 2
// 4 0 0 0 0 0 0 0 0
// 4 0 0 0 0 0 0 0 0