#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int res;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> str;
        stack<int> st;
        res = 1;
        for(auto c : str)
        {
            if(c == '(')
                st.push(c);
            if(c == ')')
            {
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                {
                    res = 0;
                    break;
                }
            }
        }
        if(!st.empty())
            res = 0;
        if (res)
            cout << "YES" << '\n';
        else   
            cout << "NO" << '\n';
    }
}
