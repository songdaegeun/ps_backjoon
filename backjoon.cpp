#include <iostream>
#include <queue>
// #include <cstring>
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
			int x = i;
			int y = j;
			int dist[11][11];
			queue<pair<int,int>> q;
			q.push({x,y});
			dist[x][y] = 1;
			while(!q.empty())
			{
				tie(x,y) = q.front(); q.pop();
				if (map[x][y] != str[dist[x][y] - 1])
					break;
				if(dist[x][y] == str.length())
				{
					ans++;
					continue;
				}
				for (int d = 0; d < 8; d++)
				{
					int nx = x + dx[d];
					int ny = y + dy[d];
					// 환형
					if(nx < 0) nx = n - 1;
					if(nx == n) nx = 0;
					if(ny < 0) ny = m - 1;
					if(ny == m) ny = 0;
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

// 3 3 2
// aaa
// aba
// aaa
// aa
// bb