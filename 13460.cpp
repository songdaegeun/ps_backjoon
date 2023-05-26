#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
#define RED 1
#define BLUE 2

using namespace std;

int n, m;
string map[11];
pair<int,int> blue_pos;
pair<int,int> red_pos;
pair<int,int> hole_pos;
int last_blue_dir = -1;
int last_red_dir = -1;


// int dist_blue[11][11];
// int dist_red[11][11];
int dist[11][11][11][11];
// pair<int,int> state[11][11];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

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

int bfs() {
	memset(dist, -1, sizeof(int) * 11 * 11 * 11 * 11);
	queue<pair<int,int>> q;
	dist[red_pos.first][red_pos.second][blue_pos.first][blue_pos.second] = 0;
	q.push(red_pos);
	q.push(blue_pos);
	while(!q.empty()) {
		int x1, y1;
		int x2, y2;
		
		tie(x1,y1) = q.front(); q.pop();	// red
		tie(x2,y2) = q.front(); q.pop();
		// 맵 기울이기
		for (int dir = 0; dir < 4; dir++)
		{
			int nx1, ny1;
			int nx2, ny2;
			nx2 = x2;
			ny2 = y2;
			while (map[nx2 + dx[dir]][ny2 + dy[dir]] != '#' && map[nx2 + dx[dir]][ny2 + dy[dir]] != 'O') {
				nx2 += dx[dir];
				ny2 += dy[dir];
			}
			if(map[nx2 + dx[dir]][ny2 + dy[dir]] == 'O') continue;
			nx1 = x1;
			ny1 = y1;
			while (map[nx1 + dx[dir]][ny1 + dy[dir]] != '#' && map[nx1 + dx[dir]][ny1 + dy[dir]] != 'O') {
				nx1 += dx[dir];
				ny1 += dy[dir];
			}
			if(map[nx1 + dx[dir]][ny1 + dy[dir]] == 'O') return (dist[x1][y1][x2][y2] + 1);
			// red와 blue가 겹칠 경우
			if(nx1 == nx2 && ny1 == ny2) {
				if(dir == 0) {
					if(x1 < x2) nx1--;
					else	nx2--;
				}
				if(dir == 2) {
					if(x1 > x2) nx1++;
					else	nx2++;
				}
				if(dir == 1) {
					if(y1 < y2) ny1--;
					else	ny2--;
				}
				if(dir == 3) {
					if(y1 > y2) ny1++;
					else	ny2++;
				}
			}
			if (dist[nx1][ny1][nx2][ny2] != -1) continue;
		
			dist[nx1][ny1][nx2][ny2] = dist[x1][y1][x2][y2] + 1;
			q.push({nx1, ny1});
			q.push({nx2, ny2});
		}
	}
	return (-1);	
}

int search_hole() {
	int cnt;
	
	cnt = bfs();
	// cout << cnt << '\n';

	if(cnt > 10)
		cnt = -1;
	return (cnt);
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


// 10 10
// ##########
// #RB....#.#
// #..#.....#
// #........#
// #.O......#
// #...#....#
// #........#
// #........#
// #.......##
// ##########