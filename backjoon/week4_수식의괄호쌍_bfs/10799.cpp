#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> stk;

    int sum = 0;
    int laser_cnt = 0;
    int laser_long_cnt = 0;
    string str;
    
    cin >> str;
    for(int i = 0; str[i]; i++)
    {
        if(str[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            if(!stk.empty())
            {
                if(i - stk.top() == 1)
                {
                    stk.pop();
                    sum += stk.size();
                }
                else
                {
                    stk.pop();
                    sum += 1;
                }
            }
        }
    }
    cout << sum;
}
