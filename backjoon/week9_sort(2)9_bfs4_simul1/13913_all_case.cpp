#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
// 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
// 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
int n, k, ans;
int dist[100001];
vector<int> v;

int bfs() {
    queue<int> q;
    dist[n] = 0;
    q.push(n);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(x == k)
            return (dist[x]);
        for(int nx : {x - 1, x + 1, 2 * x})
        {
            if(nx < 0 || nx > 100000) continue;
            if(dist[nx] != -1) continue;
            dist[nx] = dist[x] + 1;
            q.push(nx);
        }
    }
    return (0); // 여기 못옴.
}
void sol(int idx) {
    if(v.size() == ans + 1)
    {
        if(v[ans] == k)
        {
            for(auto el:v) {
                cout << el << ' ';
            }
            cout << '\n';
        }
        return ;
    }
    for(int nx : {idx - 1, idx + 1, 2 * idx})
    {
        if(nx < 0 || nx > 100000) continue;
        if(dist[nx] != -1) {
            v.push_back(nx);
            sol(nx);
            v.pop_back();
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    memset(dist, -1, sizeof(int) * 100001);
    ans = bfs();
    cout << ans << '\n';
    v.push_back(n);
    sol(n);
}

// 5 17