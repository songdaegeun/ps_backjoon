#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> height;
    stack<int> i_height;
    int tower_height;
    int index = 0;
 
    int i = 1;
    while(i <= n)
    {
        cin >> tower_height;
        while (!height.empty() && height.top() < tower_height)
        {
            height.pop();
            i_height.pop();
        }
        if (height.empty())
            index = 0;
        else
            index = i_height.top();
        height.push(tower_height);
        i_height.push(i);

        cout << index << ' ';
        i++;
    }
}
