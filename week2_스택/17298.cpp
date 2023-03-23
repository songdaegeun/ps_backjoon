#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[1000001];
    memset(arr, 0, sizeof(int) * 1000001);
    int n, i, el;
    cin >> n;
    i = 1;
    while(i <= n)
    {
        cin >> el;
        arr[i] = el;
        i++;
    }
    
    stack<int> s;
    stack<int> rev_s;
    i = n;
    while(i)
    {
        while(s.size() && s.top() <= arr[i])
        {
            s.pop();
        }
        if(!s.size())
            rev_s.push(-1);
            // cout << -1 << ' ';
        else
            rev_s.push(s.top());
            // cout << s.top() << ' ';
        s.push(arr[i]);
        i--;
    }
    while(rev_s.size())
    {
        cout << rev_s.top() << ' ';
        rev_s.pop();
    }
}