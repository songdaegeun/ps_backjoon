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
    int i;
    int cnt;

    cnt = 0;
    cin >> n;
    while(n--)
    {
        cin >> str;
        stack<char> st;
        for(auto c:str)
        {
            if(!st.empty() && st.top() == c)
                st.pop();
            else
                st.push(c);
        }
        if(st.empty())
            cnt++;
    }
    cout << cnt;
}
