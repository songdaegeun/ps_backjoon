#include <iostream>
#include <queue>
#include <deque>
#include <unordered_map>
#define EMPTY 0
#define WALL 1
#define APPLE 2
#define BAM 3
using namespace std;

deque<pair<int,int>> bam;
vector<pair<int,int>> apple;

int map[102][102];
int map_base[102][102];

int n, k, ans;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void disp_map() {
	cout << '\n';
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void copy_map() {
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			map_base[i][j] = map[i][j];
		}
	}
}

void bam_painting() {
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			map[i][j]= map_base[i][j];
		}
	}
	vector<pair<int,int>> v(bam.begin(), bam.end());
	for(auto el:v) {
		map[el.first][el.second] = BAM;
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	
	cin >> n >> k;
	unordered_map<int,char> path;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		apple.push_back({x, y});
	}
	int dir_num;
	cin >> dir_num;
	for (int i = 0; i < dir_num; i++)
	{
		int t; char c;
		cin >> t >> c;
		path[t] = c;
	}
	// map을 만들어준다.
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			if (i == 0 || i == n + 1 || j == 0 || j == n + 1)
				map[i][j] = WALL;
			else
				map[i][j] = EMPTY;
		}
	}
	for(auto el:apple) {
		map[el.first][el.second] = APPLE;
	}
	copy_map();
	// 초기 위치는 1, 1
	bam.push_front({1,1});
	int dir = 1;
	// loop가 시작할때마다 ans++
	while(1) {
		ans++;
		bam_painting();
		pair<int,int> cur_head = bam.front();
		pair<int,int> next_head;
		next_head = make_pair(cur_head.first + dx[dir], cur_head.second + dy[dir]);	
		int next_state = map[next_head.first][next_head.second];
		if(next_state == WALL || next_state == BAM)
			break;
		if(next_state != APPLE)
			bam.pop_back();
		else {
			map_base[cur_head.first + dx[dir]][cur_head.second + dy[dir]] = EMPTY;
		}
		bam.push_front(next_head);
		// 방향 전환 타이밍인지 확인
		if(path.find(ans) != path.end()) {
			if (path[ans] == 'L') {
				dir = (dir + 3) % 4;
			}
			else if(path[ans] == 'D') {
				dir = (dir + 1) % 4;
			}
		}
	}
	// bam.front()의 좌표에서 뱀의 방향에 따라 추가된 좌표를 bam.push_front()
	// bam_painting(); // bam의 모든 요소에 해당하는 map의 좌표를 BAM으로 변경
	// 만약 벽 or 뱀이면 break;
	// 만약 사과이면 아무것도 안함
	// 만약 공간이면 bam.pop_back()
	// disp_map();
	cout << ans << '\n';
}
// i == 0 || i == n - 1 || j == 0 || j == n - 1 이면 벽.
// 게임이 시작할때 뱀은 0,0에 위치하고 뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.
// 게임이 끝날때까지 걸린 시간 출력

// 뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다.

// 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
// 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
// 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
// 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.

// 6
// 3  // 사과의 갯수
// 3 4
// 2 5
// 5 3
// 3  // 방향변환횟수
// 3 D
// 15 L
// 17 D