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
    memset(dist, -1, sizeof(int) * 100001);
    dist[n] = 0;
    q.push(n);
    while(dist[k] == -1){
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
            if(dist[next_pos] != -1) continue;
            dist[next_pos] = dist[pos] + 1;
            q.push(next_pos);
        }
    }
    cout << dist[k];
}
