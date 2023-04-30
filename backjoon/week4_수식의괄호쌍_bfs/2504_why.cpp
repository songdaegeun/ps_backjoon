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
    int two_flag = 1;
    int three_flag = 1;

    cin >> str;
    for(auto c:str)
    {
        if (c == '(')
        {
            two_flag = 1;
            two_stk.push(c);
        }
        else if(c == '[')
        {
            three_flag = 1;
            three_stk.push(c);
        }
        else
        {
            if(c == ')')
            {
                if(!two_stk.empty() && two_stk.top() == '(')
                {
                    // 계산
                    if (two_flag == 1)
                    {
                        res += pow(2, two_stk.size()) * pow(3, three_stk.size());
                        two_flag = 0;
                        three_flag = 0;
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
                    // 계산
                    if (three_flag == 1)
                    {
                       res += pow(2, two_stk.size()) * pow(3, three_stk.size());
                       three_flag = 0;
                       two_flag = 0;
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
