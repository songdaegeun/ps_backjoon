#include <iostream>
#include <unordered_map>
using namespace std;

string map[11];
string str;
int n, m, k;
int dx[8] = {1,0,-1,0,1,-1,1,-1};
int dy[8] = {0,1,0,-1,1,1,-1,-1};
unordered_map<string,int> path_mem;

void dfs(int depth, int x, int y, string path) {
	path_mem[path]++;
	if(depth == 4)	// 1 ≤ 신이 좋아하는 문자열의 길이 ≤ 5
	{
		return ;
	}
	for (int d = 0; d < 8; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];
		// 환형 연결
		nx = (n + nx) % n;
		ny = (m + ny) % m;
		dfs(depth + 1, nx, ny, path + map[nx][ny]);
	}
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			string s(1, map[i][j]);
			dfs(0, i, j, s);
		}
	}
	for (int i = 0; i < k; i++)
	{
		
		cin >> str;	
		cout << path_mem[str] << '\n';
	}
	
}

// 3 4 3
// abcb
// bcaa
// abac
// abcb
// abc
// cab