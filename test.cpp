#include <iostream>
#include <cstring>
using namespace std;

char map[6145][6145];

void disp_map(int n)
{
	int width = 2 * n - 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}

void print_map(int n, int x, int y)
{
	if(n == 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 2 * i + 1; j++)
			{
				if(i == 1 && j == 1)
					continue;
				map[x + i][y - i + j] = '*';
			}
		}
		return ;
	}
		
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2 * i + 1; j++)
		{
			if(i == 1 && j == 1)
				continue;
			print_map(n / 2, x + i * (n / 2) , y + i * (j - 1) * (n / 2) );
		}
		
	}
	
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n;
	cin >> n;
	memset(map, ' ', 6145 * 6145);
	print_map(n, 0, n - 1);
	disp_map(n);
}
