#include <iostream>
#include <queue>
#define	EMPTY 0
#define	WALL 1
#define	CLEAN 2

using namespace std;

int n, m, r, c, d;
int state[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void disp_map()
{
	for (int i = 0; i < n; i++)
	{
		cout << '\n';
		for (int j = 0; j < m; j++)
		{
			cout << state[i][j] << ' ';
		}
	}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> state[i][j];
		}
	}
	d = (4 - d) % 4;
	queue<tuple<int,int,int>> q;
	q.push({r,c,d});
	int ans = 0;
	while(!q.empty()) {
		int x, y, d;
		tie(x,y,d) = q.front(); q.pop();
		if(state[x][y] == EMPTY)
		{
			state[x][y] = CLEAN;
			ans++;
		}
		int i;
		for (i = d; i < d + 4; i++)
		{
			int dir = i % 4;
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (state[nx][ny] == EMPTY)
			{
				q.push({nx, ny, dir});
				break;
			}
		}
		if (i == (d + 4)) {
			if(state[x - dx[d]][y - dy[d]] != WALL) // 후진가능하면
				q.push({x - dx[d], y - dy[d], d});
			else
				break;
		}
	}
	cout << ans << '\n';
	disp_map();
}
// 0: 청소 x, 1: 벽
// 로봇 청소기가 작동을 시작한 후 작동을 멈출 때까지 청소하는 칸의 개수를 출력.

// 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
// 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
// 1) 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
// 2) 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
// 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
// 1) 반시계 방향으로 90도 회전한다.
// 2) 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
// 3) 1번으로 돌아간다.

// 3 3
// 1 1 0
// 1 1 1
// 1 0 1
// 1 1 1