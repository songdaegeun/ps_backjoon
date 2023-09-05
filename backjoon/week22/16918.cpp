#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int r,c,n;
char board[201][201];
int	visited_1[201][201];
int	visited_2[201][201];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void disp_board()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}
}

void chk_bomb(vector<pair<int,int>> &location)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'O') {
				location.push_back({i,j});
			}
		}
	}
}

void locate_bomb(vector<pair<int,int>> &location)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if(board[i][j] != 'O') {
				board[i][j] = 'O';
				location.push_back({i,j});
			}
		}
	}
}

void bomb(vector<pair<int,int>> &location, int flag)
{
	int x,y;

	if(flag == 1) {
			for(auto pos: location) {
			x = pos.first;
			y = pos.second;
			if(visited_1[x][y]) continue;
			board[x][y] = '.';
			visited_2[x][y] = 1;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx < 0 || nx >= r || ny < 0 || ny >= c)
					continue;
				board[nx][ny] = '.';
				visited_2[nx][ny] = 1;
			}
		}
	}
	else if(flag == 2) {
		for(auto pos: location) {
			x = pos.first;
			y = pos.second;
			if(visited_2[x][y]) continue;
			board[x][y] = '.';
			visited_1[x][y] = 1;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx < 0 || nx >= r || ny < 0 || ny >= c)
					continue;
				board[nx][ny] = '.';
				visited_1[nx][ny] = 1;
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> r >> c >> n;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	// check bomb location (0)
	vector<pair<int,int>> location_1;
	vector<pair<int,int>> location_2;
	chk_bomb(location_1);
	
	// nothing (1)
	int i = 2; // 2
	int flag = 1;
	while(i <= n)
	{
		if(i % 2 == 1) {
			if(flag == 1) { // 3
				bomb(location_1, 1);
				location_1.clear();
				memset(visited_1, 0, sizeof(visited_1));
				flag = 0;
			}
			else { // 5
				bomb(location_2, 2);
				location_2.clear();
				memset(visited_2, 0, sizeof(visited_2));
				flag = 1;
			}
		}
		else {
			// install bomb to empty space (2)
			if(flag == 1) {
				locate_bomb(location_2);
			}
			else { // 4
				locate_bomb(location_1);
			}
		}
		i++;
	}
	disp_board();
}

// 6 7 3
// .......
// ...O...
// ....O..
// .......
// OO.....
// OO.....

// 가장 처음에 봄버맨은 일부 칸에 폭탄을 설치해 놓는다. 모든 폭탄이 설치된 시간은 같다.
// 다음 1초 동안 봄버맨은 아무것도 하지 않는다.
// 다음 1초 동안 폭탄이 설치되어 있지 않은 모든 칸에 폭탄을 설치한다. 즉, 모든 칸은 폭탄을 가지고 있게 된다. 폭탄은 모두 동시에 설치했다고 가정한다.
// 1초가 지난 후에 3초 전에 설치된 폭탄이 모두 폭발한다.
// 3과 4를 반복한다.
