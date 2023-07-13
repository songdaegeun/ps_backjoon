#include <iostream>
#include <string.h>
using namespace std;

int n, l;
int map[101][101];
int tilt_road[101][101];
int ans;  // max: 2*n

void disp()
{
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		cout << '\n';
		for (int j = 0; j < n; j++)
		{
			cout << tilt_road[i][j] << ' ';
		}
	}
}

int can_set(int row, int col, int dir)
{
	int flag = 1;

	int prev;
	if(dir == 1) {
		prev = map[row][col];
		for(int i = 0; i < l; i++) {
			int now = map[row][col+i];
			if(now != prev) {
				flag = 0;
				break;
			}
			if(tilt_road[row][col+i] == 1) {
				flag = 0;
				break;
			}
			prev = now;
		}
	}
	else if(dir == -1) {
		prev = map[row][col];
		for(int i = 0; i < l; i++) {
			int now = map[row][col-i];
			if(now != prev) {
				flag = 0;
				break;
			}
			if(tilt_road[row][col-i] == 1) {
				flag = 0;
				break;
			}
			prev = now;
		}
	}
	else if(dir == 2) {
		prev = map[row][col];
		for(int i = 0; i < l; i++) {
			int now = map[row+i][col];
			if(now != prev) {
				flag = 0;
				break;
			}
			if(tilt_road[row+i][col] == 1) {
				flag = 0;
				break;
			}
			prev = now;
		}
	}
	else if(dir == -2) {
		prev = map[row][col];
		for(int i = 0; i < l; i++) {
			int now = map[row-i][col];;
			if(now != prev) {
				flag = 0;
				break;
			}
			if(tilt_road[row-i][col] == 1) {
				flag = 0;
				break;
			}
			prev = now;
		}
	}
	if(flag == 1)
		return (1);
	else	
		return (0);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		memset(tilt_road, 0, sizeof(tilt_road));
		int prev_h = map[i][0];
		int flag = 1;
		for (int j = 0; j < n; j++)
		{
			int h = map[i][j];
			
			if((prev_h - 1) == h) {
				if ((n - j) >= l && can_set(i, j, 1)) {
					// l만큼 tilt_road를 set
					int cnt = l;
					while(cnt--) {
						tilt_road[i][j] = 1;
						j++;
					}
					j--;
				}
				else
				{
					flag = 0;
					break;
				}
				prev_h = h;
			}
			else if(prev_h == h) {
				prev_h = h;
			}
			else {
				flag = 0;
				prev_h = h;
			}
		}
		if(flag == 1) {
			ans++;
			continue;
		}
		prev_h = map[i][n-1];
		flag = 1;
		for (int j = n-1; j >= 0; j--)
		{
			int h = map[i][j];

			if((prev_h - 1) == h) {
				if ((j+1) >= l && can_set(i, j, -1)) {
					// l만큼 tilt_road를 set
					int cnt = l;
					while(cnt--) {
						tilt_road[i][j--] = 1;
					}
					j++;
				}
				else
				{
					flag = 0;
					break;
				}
				prev_h = h;
			}
			else if(prev_h == h) {
				if(tilt_road[i][j] == 1) {
					j -= (l - 1);
					prev_h = h + 1;
				}
				else
					prev_h = h;
			}
			else {
				flag = 0;
				break;
			}
		}
		if(flag == 1) {
			ans++;
		}
	}
	memset(tilt_road, 0, sizeof(tilt_road));
	for (int j = 0; j < n; j++)
	{
		memset(tilt_road, 0, sizeof(tilt_road));
		int prev_h = map[0][j];
		int flag = 1;
		for (int i = 0; i < n; i++)
		{
			int h = map[i][j];
			
			if((prev_h - 1) == h) {
				if ((n - i) >= l && can_set(i, j, 2)) {
					// l만큼 tilt_road를 set
					int cnt = l;
					while(cnt--) {
						tilt_road[i][j] = 1;
						i++;
					}
					i--;
				}
				else
				{
					flag = 0;
					break;
				}
				prev_h = h;
			}
			else if(prev_h == h) {
				prev_h = h;
			}
			else {
				flag = 0;
				prev_h = h;
			}
		}
		if(flag == 1) {
			ans++;
			continue;
		}
		prev_h = map[n-1][j];
		flag = 1;
		for (int i = n-1; i >= 0; i--)
		{
			int h = map[i][j];

			if((prev_h - 1) == h) {
				if ((i+1) >= l && can_set(i, j, -2)) {
					// l만큼 tilt_road를 set
					int cnt = l;
					while(cnt--) {
						tilt_road[i][j] = 1;
						i--;
					}
					i++;
				}
				else
				{
					flag = 0;
					break;
				}
				prev_h = h;
			}
			else if(prev_h == h) {
				if(tilt_road[i][j] == 1) {
					i -= (l - 1);
					prev_h = h + 1;
				}
				else {
					prev_h = h;
				}
			}
			else {
				flag = 0;
				break;
			}
		}
		if(flag == 1) {
			ans++;
		}
	}
	cout << ans;
}

// 1.각 행과 열에 대해서 양쪽 방향으로 길인지 체크.(2*n*2)
// 2.높이가 모두 같다면 길이다.
// 3.이전 높이보다 현재 높이가 1작다면, 길이 l만큼 높이가 같은지 && 경사로가 설치되지 않았는지 확인 . 
// 4.길이l만큼 같다면, 경사로 설치. 설치된 영역은 체크.
// 5.길이가 끝날때까지 2-4반복.

// 6 2
// 3 3 3 3 3 3
// 2 3 3 3 3 3
// 2 2 2 3 2 3
// 1 1 1 2 2 2
// 1 1 1 3 3 1
// 1 1 2 3 3 2