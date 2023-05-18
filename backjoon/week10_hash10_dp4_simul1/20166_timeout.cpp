#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

string map[11];
string str;
int ans;
int n, m, k;
int dx[8] = {1,0,-1,0,1,-1,1,-1};
int dy[8] = {0,1,0,-1,1,1,-1,-1};

void sol() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// map에서 시작할 수 있는 모든 경우에 대해 생각한다.
			// str.length()만큼 이동한다.
			// str의 한글자와 일치할때마다 그 다음으로 넘어간다.
			if (map[i][j] != str[0])
				continue;
			int x = i;
			int y = j;
			int dist[11][11];
			memset(dist, 0, sizeof(int) * 11 * 11);
			queue<pair<int,int>> q;
			q.push({x,y});
			dist[x][y] = 1;
			while(!q.empty())
			{
				tie(x,y) = q.front(); q.pop();
				if(dist[x][y] == (int)str.length())
				{
					ans++;
					continue;
				}
				for (int d = 0; d < 8; d++)
				{
					int nx = x + dx[d];
					int ny = y + dy[d];
					// 환형 연결
					nx = (n + nx) % n;
					ny = (m + ny) % m;
					if (map[nx][ny] != str[dist[x][y]])
						continue;
					q.push({nx,ny});
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
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
		cin >> map[i];
	}
	for (int i = 0; i < k; i++)
	{
		
		cin >> str;	// str은 중복가능
		ans = 0;
		// 아무데서나 상하좌우대각이동 가능, 환형이동가능.
		// 경우의 수를 셀 때, 방문 순서가 다르면 다른 경우이다.
		sol();
		// str을 만들 수 있는 경우의 수 출력.
		cout << ans << '\n';
	}
	
}

// 3 4 3
// abcb
// bcaa
// abac
// abcb
// abc
// cab