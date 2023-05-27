#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int n, m;
string map[11];
pair<int,int> blue_pos;
pair<int,int> red_pos;
pair<int,int> hole_pos;

int dist_blue[11][11];
int dist_red[11][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int last_blue_dir = -1;
int last_red_dir = -1;

void dispmap() {
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

pair<int,int> tilt_map(int dir, int x, int y) {
	int nx, ny;

	nx = x;
	ny = y;
	while (map[nx][ny] != '#') {
		nx += dx[dir];
		ny += dy[dir];
		
		if(nx == hole_pos.first && ny == hole_pos.second)
			break;
	}
	if(map[nx][ny] == '#') {
		nx -= dx[dir];
		ny -= dy[dir];
	}
	pair<int,int> pos;
	pos = make_pair(nx, ny);
	return (pos);
}

int bfs_red() {
	memset(dist_red, -1, sizeof(int) * 11 * 11);
	queue<pair<int,int>> q;

	dist_red[red_pos.first][red_pos.second] = 0;
	q.push(red_pos);
	while(!q.empty()) {
		int x, y;
		tie(x,y) = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			// 맵 기울이기
			pair<int,int> new_pos;
			int nx, ny;
			new_pos = tilt_map(i, x, y);
			tie(nx,ny) = new_pos;
			if(nx == hole_pos.first && ny == hole_pos.second) {
				last_red_dir = i;
				return (dist_red[x][y] + 1);
			}
				
			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if(dist_red[nx][ny] != -1) continue;
			dist_red[nx][ny] = dist_red[x][y] + 1;
			q.push({nx, ny});
		}
	}
	return (-1);	
}

int bfs_blue() {
	memset(dist_blue, -1, sizeof(int) * 11 * 11);
	queue<pair<int,int>> q;

	dist_blue[blue_pos.first][blue_pos.second] = 0;
	q.push(blue_pos);
	while(!q.empty()) {
		int x, y;
		tie(x,y) = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			// 맵 기울이기
			pair<int,int> new_pos;
			int nx, ny;
			new_pos = tilt_map(i, x, y);
			tie(nx,ny) = new_pos;
			if(nx == hole_pos.first && ny == hole_pos.second) {
				last_blue_dir = i;
				return (dist_blue[x][y] + 1);
			}
			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if(dist_blue[nx][ny] != -1 || dist_red[ny][ny] != -1 && dist_blue[x][y] + 1 >= dist_red[ny][ny]) continue;
			dist_blue[nx][ny] = dist_blue[x][y] + 1;
			q.push({nx, ny});
		}
	}
	return (-1);
}

int search_hole() {
	int blue_cnt;
	int red_cnt;
	
	red_cnt = bfs_red();
	cout << red_cnt << '\n';
	blue_cnt = bfs_blue();
	cout << blue_cnt << '\n';

	if(blue_cnt == red_cnt && last_blue_dir == last_red_dir || red_cnt > 10)
		red_cnt = -1;
	return (red_cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < m; j++)
		{	
			map[i][j] = str[j];
			if(map[i][j] == 'B') {
				blue_pos.first = i;
				blue_pos.second = j;
			}
			if(map[i][j] == 'R') {
				red_pos.first = i;
				red_pos.second = j;
			}
			if(map[i][j] == 'O') {
				hole_pos.first = i;
				hole_pos.second = j;
			}
		}
	}
	
	// B가 R의 경로앞에 오면 R을 먼저 구멍에 넣을 수 없으므로 return (-1) 한다.
	// 즉, 기울인 후 B와 R의 위치가 일치하면 return (-1)한다.
	// 모든 경로를 탐색한 후에도 구멍에 들어갈 수 없으면 return (-1) 한다.
	// 구멍에 들어갔지만 움직인 횟수가 10번 초과면 return (-1) 한다.
	// 4방향에 대해 움직인 결과는 bfs로 들어가야한다.
	cout << search_hole() << '\n';
}

// 각각의 동작에서 공은 동시에 움직인다. 
// 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 
// 빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 
// 또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.

// 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다. 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.


// 7 7
// #######
// #...BR#
// #.#####
// #.....#
// #####.#
// #O....#
// #######