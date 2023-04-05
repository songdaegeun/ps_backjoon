#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> two_stk;
    stack<char> three_stk;
    string str;
    int res = 0;
    char c;

    cin >> str;
    for(int i = 0; str[i]; i++)
    {
        c = str[i];
        if (c == '(')
        {
            two_stk.push(c);
        }
        else if(c == '[')
        {
            three_stk.push(c);
        }
        else
        {
            if(c == ')')
            {
                if(!two_stk.empty() && two_stk.top() == '(')
                {
                    if (str[i - 1] == '(')
                    {
                        res += pow(2, two_stk.size()) * pow(3, three_stk.size());
                    }
                    two_stk.pop();
                }
                else
                {
                    res = 0;
                    break;
                }
            }
            else
            {
                if(!three_stk.empty() && three_stk.top() == '[')
                {
                    if (str[i - 1] == '[')
                    {
                        res += pow(2, two_stk.size()) * pow(3, three_stk.size());
                    }
                    three_stk.pop();
                }
                else
                {
                    res = 0;
                    break;
                }
            }
        }
    }
    if(!three_stk.empty() || !two_stk.empty())
        res = 0;
    cout << res;
}

// (()[[]])([])
