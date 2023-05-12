#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
// 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
// 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.
int n, k;
int dx[2] = {-1, 1};
int dist[100001];

int bfs() {
    queue<int> q;
    dist[n] = 0;
    q.push(n);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(x == k)
            return (dist[x]);
        // 순간이동해서 만나는지 확인
        int nx = x;
        while(nx != 0 && nx <= 100000) {
            nx *= 2;
            if(nx == k)
                return (dist[x]);
            if(nx < 0 || nx > 100000) continue;
            if(dist[nx] != -1) continue;
            dist[nx] = dist[x];
            q.push(nx);
            
        }
        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[i];
            if(nx < 0 || nx > 100000) continue;
            if(dist[nx] != -1) continue;
            dist[nx] = dist[x] + 1;
            q.push(nx);
        }
    }
    return (0); // 여기 못옴.
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    memset(dist, -1, sizeof(int) * 100001);
    int ans = bfs();
    cout << ans;
}

// 5 17