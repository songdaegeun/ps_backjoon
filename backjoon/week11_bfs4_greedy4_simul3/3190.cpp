#include <iostream>
#include <deque>
#include <queue>
#define EMPTY 0
#define WALL 1
#define APPLE 2
#define BAM 3
using namespace std;

deque<pair<int,int>> bam;
queue<pair<int,int>> path;

int map[102][102];

int n, k, ans;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void disp_map() {
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = APPLE;
	}
	int dir_num;
	cin >> dir_num;
	for (int i = 0; i < dir_num; i++)
	{
		int t; char d;
		cin >> t >> d;
		path.push({t,(int)d});
	}
	bam.push_front({0,0});
	int dir = 1;
	// loop가 시작할때마다 ans++
	while(1) {
		ans++;
		pair<int,int> cur_head = bam.front();
		int nx, ny;
		nx = cur_head.first + dx[dir];
		ny = cur_head.second + dy[dir];
		pair<int,int> next_head(nx, ny);
		if(nx < 0 || nx >= n || ny < 0 || ny >= n)
			break;
		int next_state = map[nx][ny];
		if(next_state == WALL || next_state == BAM)
			break;
		if(next_state != APPLE) {
			pair<int,int> cur_tail = bam.back();
			map[cur_tail.first][cur_tail.second] = EMPTY;
			bam.pop_back();
		}
		map[next_head.first][next_head.second] = BAM;
		bam.push_front(next_head);
		// 방향 전환 타이밍인지 확인
		if (path.front().first == ans) {
			if (path.front().second == 'L') {
				dir = (dir + 3) % 4;
			}
			else if(path.front().second == 'D') {
				dir = (dir + 1) % 4;
			}
			path.pop();
		}
	}
	cout << ans << '\n';
}

// 6
// 3  
// 3 4
// 2 5
// 5 3
// 3 
// 3 D
// 15 L
// 17 D