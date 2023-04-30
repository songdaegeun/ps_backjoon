#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int stu[100002];
int state[100002];

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
        memset(state, 0, sizeof(int) * 100002);
        for(int i = 1; i <= n; i++)
        {
            if(state[i] != 0) continue;
            // if visited, not loop in
            int cur = i;
            while(1)
            {
                state[cur] = i;
                // remember first check student.
                cur = stu[cur];
                // next student.
                if(state[cur] == i)
                {
                    while(state[cur] != -1)
                    {
                        // check students to success making team.
                        state[cur] = -1;
                        cur = stu[cur];
                    }
                    break;
                }
                else if(state[cur] != 0)
                {
                    break;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if(state[i] != -1)
                cnt++;
        }
        cout << cnt << '\n';
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

