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
        string cmd;
        cin >> cmd;
        if(cmd == "push")
        {
            int c;
            cin >> c;
            s.push(c);
            // s[ptr++] = c
        }
        else if(cmd == "pop")
        {
            if(s.empty())
                cout << "-1\n";
            else
            {
                cout << s.top() << "\n";
                //s[ptr - 1]
                s.pop();
                //ptr--
            }
        }
        else if(cmd == "size")
        {
            cout << s.size() << "\n";
            //ptr
        }
        else if(cmd == "empty")
        {
            cout << s.empty() << "\n";
        }
        else if(cmd == "top")
        {
            if(s.empty())
                cout << "-1\n";
            else
            {
                cout << s.top() << "\n";
                //s[ptr - 1]
            }
        }
    }
}

// push X: 정수 X를 스택에 넣는 연산이다.
// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 스택에 들어있는 정수의 개수를 출력한다.
// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.