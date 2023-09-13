#include <iostream>
using namespace std;

int map[6][6];
int visited[6][6];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int prev_x;
	int prev_y;
	int first_x, first_y;
	int flag = 1;
	for (int i = 0; i < 36; i++)
	{
		string str;
		cin >> str;
		int x, y;
		x = str[0] - 'A';
		y = str[1] - '1';
		// cout << x << ' ' << y << '\n';
		if(i != 0)
		{
			if(abs(x - prev_x) == 2 && abs(y - prev_y) == 1) {
			visited[x][y] = 1;
			}
			else if(abs(y - prev_y) == 2 && abs(x - prev_x) == 1) {
				visited[x][y] = 1;
			}
			else {
				flag = 0;
			}
		}
		else {
			first_x = x;
			first_y = y;
			visited[x][y] = 1;
		}
		prev_x = x;
		prev_y = y;
	}
	if(abs(prev_y - first_y) == 2 && abs(prev_x - first_x) == 1)  {
		;
	}
	else if(abs(prev_y - first_y) == 1 && abs(prev_x - first_x) == 2)  {
		;
	}
	else
		flag = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if(visited[i][j] == 0)
				flag = 0;
		}
	}
	if(!flag) {
		cout << "Invalid\n";
	}
	else {
		cout << "Valid\n";
	}
}

// A1
// B3
// A5
// C6
// E5
// F3
// D2
// F1
// E3
// F5
// D4
// B5
// A3
// B1
// C3
// A2
// C1
// E2
// F4
// E6
// C5
// A6
// B4
// D5
// F6
// E4
// D6
// C4
// B6
// A4
// B2
// D1
// F2
// D3
// E1
// C2