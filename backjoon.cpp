#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, el;
    long long sum;
    cin >> n;
    stack<int> s;
    sum = 0;
    while(n--)
    {
        cout << '[' << s.size() << ']';
        sum += s.size();
        cin >> el;
        while(s.size() && s.top() < el)
        {
            s.pop();
        }
        s.push(el);
    }
    cout << sum;
}

// 7
// 2
// 4
// 3
// 2
// 1
// 5
// 1