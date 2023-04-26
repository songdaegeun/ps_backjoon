#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int stu[100002];
int dist[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int tc, n;
    queue<int> q;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> stu[i];
        }
        memset(dist, -1, sizeof(int) * 100002);
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(dist[i] != -1) continue;
            // if visited, not loop in
            dist[0] = i;
            // remember first check student.
            dist[i] = 1;
            int cur = i;
            // q.push(i);
            while(1)
            {
                // int stu_i = q.front(); q.pop();
                int stu_i = cur;
                int next_stu_i = stu[stu_i];
                if(dist[next_stu_i] != -1)
                {
                    // if visited, not loop in
                    if(next_stu_i == dist[0]) cnt += dist[stu_i];
                    else if(stu_i == next_stu_i) cnt += 1; 
                    // 반례가 부족하다. dist[0]가 next_stu_i가 아닌 경우, stu_i == next_stu_i말고도 부분적인 폐회로는 존재할 수 있다. (3, 3, 2)그래서 틀림.
                    break;
                }
                dist[next_stu_i] = dist[stu_i] + 1;
                // q.push(next_stu_i);
                cur = next_stu_i;
            }
        }
        cout << n - cnt << '\n';
    }
}
// 3
// 7
// 3 1 3 7 3 4 6
// 8
// 1 2 3 4 5 6 7 8
// 3
// 1 1 1

// 1
// 3
// 3 1 2

// 1
// 2
// 1 1

// 1
// 2
// 2 2

// 1
// 3
// 3 3 2
