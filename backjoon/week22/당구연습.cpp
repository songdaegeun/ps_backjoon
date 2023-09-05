#include <string>
#include <vector>
#include <climits>

using namespace std;

int calc_dist(int nx, int ny, int x, int y)
{
    return ((nx - x) * (nx - x) + (ny - y) * (ny - y));
}

int g_m, g_n;

int reflect_dist(vector<int> &ball, int x, int y)
{
    int min_val = INT_MAX;
    int dist;
    // 4축에 대해서 대칭
    // y = 0, g_m / x = 0, g_n
    // {-x, y} {2*g_m - x, y}, {x, -y}, {x, 2*g_n - y}
    int nx_arr[4] = {-x, 2*g_m - x, x, x};
    int ny_arr[4] = {y ,  y       ,-y, 2*g_n - y};
        
    for(int i = 0; i < 4; i++) {
        int nx = nx_arr[i];
        int ny = ny_arr[i];
        if (x == ball[0]) {
            if ((y - ball[1]) * (ny - ball[1]) < 0)
                continue;
        }
        if (y == ball[1]) {
            if ((x - ball[0]) * (nx - ball[0]) < 0)
                continue;
        }
        dist = calc_dist(nx,ny,ball[0],ball[1]);
        if(dist < min_val)
            min_val = dist;
    }
    return (min_val);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    g_m = m;
    g_n = n;
    
    // m x n
    // x,y을 4개의 축에 대해 대칭시킨 점을 nx,ny로 한다.
    int ds;
    for(auto ball: balls) {
        ds = reflect_dist(ball, startX, startY);
        answer.push_back(ds);
    }
    return answer;
}
