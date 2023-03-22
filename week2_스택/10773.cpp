#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int n;
    cin >> n;
    while(n--)
    {
        int dallar;
        cin >> dallar;
        if(dallar != 0)
           s.push(dallar);
        else
            s.pop();
    }
    int sum = 0;
    while(s.size())
    {
        sum += s.top();
        s.pop();
    }
    cout << sum << "\n";
}
