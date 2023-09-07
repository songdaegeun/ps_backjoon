#include<vector>
#include <stack>
#include <iostream>
#include <cstring>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visit[10][10];
int max_val = -1;

int solution(vector<vector<int> > board)
{
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            memset(visit, 0, sizeof(visit));
            stack<pair<int, int>> st;
            int type = board[i][j];
            int len = 0;

            st.push({i,j});
            visit[i][j] = 1;
            while (!st.empty()) {
                auto pos = st.top();
                st.pop();
                len++;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = pos.first + dx[dir];
                    int ny = pos.second + dy[dir];
                    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
                        continue;
                    if (visit[nx][ny] == 1)
                        continue;
                    if (board[nx][ny] != type) {
                        if(max_val < len)
                            max_val = len;
                        break;
                    }
                    st.push({nx, ny});
                    visit[nx][ny] = 1;
                }
            }
        }
    }
    if(max_val == 1)
        max_val = -1;
    return max_val;
}
