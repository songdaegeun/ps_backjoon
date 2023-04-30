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
    stack<int> cmp_height;
    stack<int> i_cmp_height;
    int tower_height;
    int end_index;
 
    int i;
    i = 1;
    while(i <= n)
    {
        cin >> tower_height;
        height.push(tower_height);
        i++;
    }
    i = n;
    long long sum;
    sum = 0;
    while(i)
    {    
        while(!cmp_height.empty() &&  height.top() > cmp_height.top())
        {
            cmp_height.pop();
            i_cmp_height.pop();
        }
        if(!cmp_height.empty())
        {
            end_index = i_cmp_height.top();
        }
        else
        {
            end_index = n + 1;
        }
        sum += end_index - i - 1;
        // cout << '[' << end_index - i - 1 << ']';
        cmp_height.push(height.top());
        i_cmp_height.push(i);
        i--;
        height.pop();
    }
    cout << sum;
}
