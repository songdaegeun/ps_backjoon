#include <iostream>
using namespace std;

int t;
int x, y, dir;
// dir = 0, 1, 2, 3 // 북쪽부터 반시계
int min_max_x[2];
int min_max_y[2];

void move(int l_dir, int delta) {
	if(l_dir == 0) {
		y += delta;
		if(min_max_y[0] > y)
			min_max_y[0] = y;
		if(min_max_y[1] < y)
			min_max_y[1] = y;
	}
	else if(l_dir == 1) {
		x -= delta;
		if(min_max_x[0] > x)
			min_max_x[0] = x;
		if(min_max_x[1] < x)
			min_max_x[1] = x;
	}
	else if(l_dir == 2) {
		y -= delta;
		if(min_max_y[0] > y)
			min_max_y[0] = y;
		if(min_max_y[1] < y)
			min_max_y[1] = y;
	}
	else if(l_dir == 3) {
		x += delta;
		if(min_max_x[0] > x)
			min_max_x[0] = x;
		if(min_max_x[1] < x)
			min_max_x[1] = x;
	}
	// cout << x << ' ' << y << '\n';
}

int solve(string str) {

	for (int i = 0; i < str.size(); i++)
	{
		if(str[i] == 'F') {
			move(dir, 1);
		}
		else if(str[i] == 'B') {
			move(dir, -1);
		}
		else if(str[i] == 'L') {
			dir++;
			dir = dir % 4;
		}
		else if(str[i] == 'R') {
			dir = dir + 3;
			dir = dir % 4;
		}
	}
	int ret = 0;
	if(min_max_x[0] == 1000 || min_max_y[0] == 1000)
		;
	else
		ret = (min_max_x[1] - min_max_x[0]) * (min_max_y[1] - min_max_y[0]);
	// cout << min_max_x[0] << ' ' << min_max_x[1] << ' ' << min_max_y[0] << ' ' << min_max_y[1] << '\n';
	return (ret);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> t;
	while(t--) {
		x = 0;
		y = 0;
		min_max_x[0] = 0;
		min_max_x[1] = 0;

		min_max_y[0] = 0;
		min_max_y[1] = 0;
		string str;
		cin >> str;
		cout << solve(str) << '\n';
	}
}

// 3
// FFLF
// FFRRFF
// FFFBBBRFFFBBB