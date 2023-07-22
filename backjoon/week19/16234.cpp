#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int A[51][51];
int can_visit[51][51];
int union_average_people[1500];
int n, l, r;
int day;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void disp(int (&map)[51][51])
{
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		cout << '\n';
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << ' ';
		}
	}
}

int abs(int a, int b) {
	if(a>=b){
		return (a-b);
	}
	else {
		return (b-a);
	}
}
int range_chk(int a, int b)
{
	int dist = abs(a,b);
	if(dist >= l && dist <= r) {
		return (1);
	}
	return (0);
}

void chk_can_visit()
{
	int union_id = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = i; int y = j;
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if(range_chk(A[x][y], A[nx][ny])) {
					can_visit[x][y] = union_id;
					can_visit[nx][ny] = union_id;
				}
			}
		}
	}
}

int union_chk() {
	int visit[51][51];
	memset(visit, 0, sizeof(visit));
	int union_id = 1;
	memset(union_average_people, 0, sizeof(union_average_people));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(visit[i][j] != 0 || can_visit[i][j] == 0) continue;			
			queue<pair<int,int>> q;
			q.push({i,j});
			visit[i][j] = 1;
			int num_of_country = 0;
			int num_of_people = 0;
			while(!q.empty())
			{
				int x,y;
				tie(x,y) = q.front(); q.pop();
				can_visit[x][y] = union_id;
				num_of_country++;
				num_of_people += A[x][y];
				for (int k = 0; k < 4; k++)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(visit[nx][ny] != 0 || can_visit[nx][ny] == 0 || !range_chk(A[x][y], A[nx][ny])) continue;	
					q.push({nx,ny});
					visit[nx][ny] = 1;
				}
			}
			union_average_people[union_id++] = num_of_people / num_of_country;
			// cout << num_of_people << ' ' << num_of_country << ' ' << num_of_people / num_of_country << '\n';
		}
	}
	return (union_id);
}

void set_move() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(can_visit[i][j] == 0) continue;
			A[i][j] = union_average_people[can_visit[i][j]]; 
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}	
	}
	while(1) {
		memset(can_visit, 0, sizeof(can_visit));
		chk_can_visit();
		// disp(can_visit);
		if(union_chk() == 1) {
			break;
		}
		set_move();
		// disp(A);
		day++;
	}
	cout << day << '\n';
}

// 인구 이동은 하루 동안 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.

// 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
// 위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
// 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
// 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
// 연합을 해체하고, 모든 국경선을 닫는다.

// 인구 이동이 며칠 동안 발생하는지 첫째 줄에 출력한다.

/*

1.	전체나라를 순회하며 임의의 나라에 대해 사방으로 인구차이를 구하고, 인구조건을 만족한다면 국경선을 연다. 
	두 나라의 국경선이 열렸으면 can_visit에 두 나라를 체크한다.
2.	전체나라를 bfs로 탐색하면서 인접영역은 can_visit이 체크된 영역이므로 인접영역에 대해서 can_visit을 1부터 증가하는 수로 설정(can_visit이 연합의 식별자가 됨)하고, 
	연합에 따라 연합의 인구수와 연합을 이루고 있는 칸의 개수를 구한다.
2-1. can_visit이 체크되지 않았으면 루프를 종료한다.
3.	전체나라를 순회하며 can_visit으로 연합을 식별하고 연합에 따라 연합의 평균인구를 A[i][j]에 대입한다.

4.	하루동안의 인구이동이 끝났으니 day++하고 1로 돌아간다. 
*/


// 2 20 50
// 50 30
// 20 40