#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int height[500001];
    memset(height, 0, sizeof(int) * 500001);
    int i;
    i = 1;
    while(i <= n)
    {
        int tower_height;
        cin >> tower_height;
        height[i++] = tower_height;
    }
    int j;
    i = 1;
    while(i <= n)
    {
        // j = i부터 height[j]의 좌측이 height[j]보다 크지 않으면 그 다음 좌측으로. 
        // j = 1까지 탐색
        // height[i]보다 큰 순간 i출력하고 그 다음 i확인
        j = i - 1;
        while(j >= 1)
        {
            if(height[j] > height[i])
            {
                cout << j << ' ';
                break;
            }
            j--;
        }
        if(j == 0)
            cout << '0' << ' ';
        i++;
    }
}
