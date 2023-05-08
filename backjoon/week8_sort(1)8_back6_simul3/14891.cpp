#include <iostream>
using namespace std;

int top[4][8];

void rotate(int top_num, int dir)
{
	int tmp[8];
	for (int i = 0; i < 8; i++) tmp[i] = top[top_num][i];
	
	if(dir == 1)
	{
		// 시계
		for (int i = 0; i < 8 - 1; i++) top[top_num][i + 1] = tmp[i];
		top[top_num][0] = tmp[7];
	}
	else if(dir == -1)
	{
		// 반시계
		for (int i = 0 + 1; i < 8; i++) top[top_num][i - 1] = tmp[i];
		top[top_num][7] = tmp[0];
	}
}

void rotate_propa(int top_num, int dir, int propa)
{
	if(top_num < 0 || top_num >= 4)
		return ;
	if((propa == 1 && top_num != 3 && top[top_num][2] != top[top_num + 1][6]) || (propa == -1 && top_num != 0 && top[top_num][6] != top[top_num - 1][2]))
	{
		rotate_propa(top_num + propa, -1 * dir, propa);
		rotate(top_num + propa, -1 * dir);
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 4개의 톱니바퀴
	// 톱니바퀴하나를 시계 / 반시계로 회전시키는 함수
	// 맞닿은 극이 같으면 변화 x. 다르면 기준 톱니바퀴의 방향과 반대로 회전.
	for (int i = 0; i < 4; i++)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < 8; j++)
		{
			top[i][j] = str[j] - '0';
		}
	}
	int n;
	cin >> n;
	while(n--)
	{
		int top_num, dir;
		cin >> top_num >> dir;
		top_num--;
		
		if(top_num != 3 && top[top_num][2] != top[top_num + 1][6])
		{
			rotate_propa(top_num + 1, -1 * dir, 1);
			rotate(top_num + 1, -1 * dir);
		}
		if(top_num != 0 && top[top_num][6] != top[top_num - 1][2])
		{
			// cout << ":" << top[top_num][6] << ':' << top[top_num - 1][2] << '\n';
			rotate_propa(top_num - 1, -1 * dir, -1);
			rotate(top_num - 1, -1 * dir);
		}
		rotate(top_num, dir);
	}
	

	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		ans += top[i][0] * (1 << i);
	}
	cout << ans;
}

// 10101111
// 01111101
// 11001110
// 00000010
// 2
// 3 -1
// 1 1