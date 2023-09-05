#include <iostream>
#include <string>
using namespace std;

int r, c;
string map[13];
int delete_map[13][13];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void disp_map()
{
	for (int i = 0; i <= r + 1; i++)
	{
		for (int j = 0; j <= c + 1; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

int bound_x[2] = {11,0};
int bound_y[2] = {11,0};

void check_bound()
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if(map[i][j] == 'X')
			{
				if(bound_x[0] > i)
					bound_x[0] = i;
				if(bound_x[1] < i)
					bound_x[1] = i;
				if(bound_y[0] > j)
					bound_y[0] = j;
				if(bound_y[1] < j)
					bound_y[1] = j;
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	for (int i = 0; i <= 11; i++)
	{
		for (int j = 0; j <= 11; j++)
		{
			map[i][j] = '.';
		}
	}
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= c; j++)
		{
			map[i][j] = str[j - 1];
		}
		
	}
	
	// disp_map();
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			int cnt = 0;
			if(map[i][j] == 'X') {
				// 4방체크 후 바다가 3개이상이면 delete_map[][] set.
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					// if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
					if(map[nx][ny] == '.')
						cnt++;
				}
				if(cnt >= 3)
					delete_map[i][j] = 1;
			}
		}
	}
	
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if(delete_map[i][j])
				map[i][j] = '.';
		}
	}
	check_bound();
	// cout << bound_x[0] << ' ' << bound_x[1] << ' ' << bound_y[0] << ' ' << bound_y[0] << '\n';
	for (int i = bound_x[0]; i <= bound_x[1]; i++)
	{
		for (int j = bound_y[0]; j <= bound_y[1]; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}

// 5 3
// ...
// .X.
// .X.
// .X.
// ...

// 'X'는 땅을 나타내고, '.'는 바다를 나타낸다.

// 지도의 크기는 모든 섬을 포함하는 가장 작은 직사각형