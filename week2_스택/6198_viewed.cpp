#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int height[80001];
    memset(height, 0, sizeof(int) * 80001);
    stack<int> s;
    stack<int> i_s;
    int tower_height;
    long long sum;
    int i;
    i = 1;
    while(i <= n)
    {
        cin >> tower_height;
        height[i] = tower_height;
        i++;
    }
    i = 1;
    sum = 0;
    while(i <= n)
    {
        while(!s.empty() && s.top() <= height[i])
        {
            s.pop();
        }
        sum += s.size();
        s.push(height[i]);

        i++;
    }

    cout << sum;
}
