#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int n, k;
int dist[2][500001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    dist[0 % 2][n] = 0;
    q.push({n, 0});
    while(!q.empty()) {
        int x, s;
        tie(x,s) = q.front(); q.pop();
        int ns = s + 1;
            
        int next_x[3] = {x - 1, x + 1, 2 * x};
        for (int i = 0; i < 3; i++)
        {
            int nx = next_x[i];
            if(nx < 0 || nx > 500000) continue;
            if(dist[ns % 2][nx] != -1) continue; 
            // 수빈이가 같은 곳을 반복방문할 가능성이 있다.
            // 그렇다고 방문한 곳을 또 방문하게 처리하면 무한루프이다.
            // 이에 대한 해결방안으로 최초방문한 시간만 dist의 요소에 기록하고 반복방문을 막으면 된다.
            // 수빈이가 가장 가까운 시간내에 같은 곳을 방문하는 경우는 2초동안 +1, -1하는 경우이다.
            // 그러므로 최초방문한 시간을 홀수/짝수 초를 나눠서 dist에 기록하면,
            // 동생이 dist에 기록된 시간의 짝수(0포함)초 후에 그곳을 방문하더라도 필연적으로 만날 수 있으므로 동생이 거기 도달하기까지 걸린 시간을 출력하면 된다.
            dist[ns % 2][nx] = ns;
            q.push({nx, s + 1});
        }
    }

    int ans = 0;
    while(k <= 500000)
    {
        if(dist[ans % 2][k] != -1 && dist[ans % 2][k] <= ans) {
            cout << ans << '\n';
            return (0);
        }
        k += ++ans;
    }
    cout << -1 << '\n';
    return (0);
}

// 17 5