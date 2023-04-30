#include <iostream>
using namespace std;

unsigned char map[32768][32768];

void map_search(int size, int x_s, int y_s, int x_e, int y_e, unsigned char *idx)
{
	if(size == 1)
	{
		for (int i = x_s; i < x_e; i++)
		{
			for (int j = y_s; j < y_e; j++)
			{
				map[i][j] = (*idx)++;
			}
		}
		return ;
	}
	map_search(size / 2, x_s, y_s, x_e / 2, y_e / 2, idx);
	map_search(size / 2, x_s, y_e / 2, x_e / 2, y_e, idx);
	map_search(size / 2, x_e / 2, y_s, x_e, y_e / 2, idx);
	map_search(size / 2, x_e / 2, y_e / 2, x_e, y_e, idx);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n, r, c;
	unsigned char idx = 0;
	cin >> n >> r >> c;
	map_search(n, 0, 0, (1 << n), (1 << n), &idx);
	cout << (int)map[r][c];
}

// 2 3 1