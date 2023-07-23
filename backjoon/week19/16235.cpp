#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k;
int A[11][11];				// 양분 투입량
int nutrient[11][11];	 	// 현재 양분
vector<pair<int,int>> state[11][11];	// {현재나이, 생존상태}
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

void disp()
{
	for (int i = 0; i < n; i++)
	{
		cout << '\n';
		for (int j = 0; j < n; j++)
		{
			for(auto el:state[i][j]) {
				cout << el.first << ',';
			}
			cout << ' ';
		}
	}
}

int oob(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= n);
}

// 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 
// 각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다. 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 
// 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.

void spring() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 어린나무부터 양분을 먹기위해 정렬
			sort(state[i][j].begin(), state[i][j].end());
			
			for(auto &el:state[i][j]) {
				// 양분이 자신의 나이이상이면 양분을 먹고 나이가 증가한다.
				if(nutrient[i][j] >= el.first) {
					nutrient[i][j] -= el.first;
					el.first++;
				}
				else {
					// 사망
					el.second = 0;
				}
			}
			// vector<pair<int,int>>::iterator it;
			// for(it = state[i][j].begin(); it != state[i][j].end(); it++) {
			// 	// 양분이 자신의 나이이상이면 양분을 먹고 나이가 증가한다.
			// 	if(nutrient[i][j] >= it->first) {
			// 		nutrient[i][j] -= it->first;
			// 		(it->first)++;
			// 	}
			// 	else {
			// 		// 사망
			// 		it->second = 0;
			// 	}
			// }
		}
	}
}

// 여름에는 봄에 죽은 나무가 양분으로 변하게 된다. 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다.
// 소수점 아래는 버린다.
void summer() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			while(!state[i][j].empty()) {
				// 뒤에서부터 죽었는지 확인
				if(state[i][j].back().second == 0) {
					nutrient[i][j] += state[i][j].back().first/2;
					state[i][j].pop_back();
				}
				else {
					break;
				}
			}
		}
	}
}

// 가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 
// 어떤 칸 (r, c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 이다.
// 상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.
void fall() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for(auto el:state[i][j]) {
				if(el.first % 5 == 0) {
					for (int dir = 0; dir < 8; dir++)
					{
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if(oob(nx,ny)) continue;
						state[nx][ny].push_back({1,1});
					}
				}
			}
		}
	}
}

// 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다.
// 각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다
void winter() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 양분 추가
			nutrient[i][j] += A[i][j];
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 양분 투입량 load
			cin >> A[i][j];
			// 현재양분 5로 set
			nutrient[i][j] = 5;
		}
	}
	while (m--)
	{
		int x,y,z;
		cin >> x >> y >> z;
		// 현재나이 및 생존상태 load
		state[x-1][y-1].push_back({z,1});
	}
	while(k--) {
		spring();
		summer();
		fall();
		winter();		
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 살아있는 나무를 센다.
			cnt += state[i][j].size();
		}
	}
	cout << cnt << '\n';
}

// 첫째 줄에 K년이 지난 후 살아남은 나무의 수를 출력한다.

// 5 2 3
// 2 3 2 3 2
// 2 3 2 3 2
// 2 3 2 3 2
// 2 3 2 3 2
// 2 3 2 3 2
// 2 1 3
// 3 2 3