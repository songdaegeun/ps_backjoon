#include <iostream>
#include <cstring>
using namespace std;

char map[6562][6562];

void disp_map(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}

// void print_unit(int x, int y, int n)
// {
// 	for (int i = x; i < x + n; i++)
// 	{
// 		for (int j = y; j < y + n; j++)
// 		{
// 			if(i == x + 1 && j == y + 1)
// 			{
// 				map[i][j] = ' ';
// 				continue;
// 			}
// 			map[i][j] = '*';
// 		}
// 	}
// }

// void space_print_unit(int x, int y, int n)
// {
// 	for (int i = x; i < x + n; i++)
// 	{
// 		for (int j = y; j < y + n; j++)
// 		{
// 			map[i][j] = ' ';
// 		}
// 	}
// }

void print_map(int x, int y, int n)
{
	if(n == 1)
	{
		map[x][y] = '*';
		return ;
	}
	int size = n / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(i == 1 && j == 1)
			{
				// space_print_unit(x + i * size, y + j * size, size);
				continue;
			}
			print_map(x + i * size, y + j * size, size);
		}
	}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n;
	cin >> n;
	memset(map, ' ', 6562 * 6562);
	print_map(0, 0, n);
	disp_map(n);
}
