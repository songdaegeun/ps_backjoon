#include <iostream>
using namespace std;

int map[65][65];
int n;

void disp_map()
{
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

int integrity_map(int x, int y, int n)
{
	for(int i = x; i < x + n; i++)
	{
		for(int j = y; j < y + n; j++)
		{
			if(map[x][y] != map[i][j])
				return (0);
		}
	}
	return (1);
}

void comp_map(int x, int y, int n)
{
	if(integrity_map(x, y, n))
	{
		cout << map[x][y];
		return ;
	}
	cout << '(';
	int size = n / 2;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			comp_map(x + i * size, y + j * size, size);
		}
	}
	cout << ')';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < n; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}
	comp_map(0, 0, n);

}

// 8
// 11110000
// 11110000
// 00011100
// 00011100
// 11110000
// 11110000
// 11110011
// 11110011