#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,k;
int dist[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    cin >> n >> k;
    memset(dist, 0, sizeof(int) * 100001);
    dist[n] = 0;    
    // 시작점과 방문하지 않은 점의 구분이 없음. 즉, 시작점을 다시 방문할 수 있음. 본 문제의 경우 n와 k가 같을 경우, dist는 0으로 끝나야하지만, 시작점과 방문하지 않은 점의 구분이 없으므로 시작점에서 dist를 0으로 set했음에도 도착점에 방문했다는 사실을 알지 못함.
    q.push(n);
    while(dist[k] == 0){
        int pos = q.front();
        q.pop();
        int next_pos_arr[3] = {pos - 1, pos + 1, pos * 2};
        for (int i = 0; i < 3; i++)
        {
            int next_pos = next_pos_arr[i];
            // if(next_pos == k)
            // {
            //     cout << dist[pos] + 1;
            //     return 0;
            // }
            if(next_pos < 0 || next_pos > 100000) continue;
            if(dist[next_pos] != 0) continue;
            dist[next_pos] = dist[pos] + 1;
            q.push(next_pos);
        }
    }
    cout << dist[k];
}
