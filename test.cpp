#include <iostream>
using namespace std;

int map[4][4];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	map[1][0] = 1;
	int** arr[1] = {(int**)map};

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	int x = 4;
	cout << (int [x])(arr[0]) << '\n';
}