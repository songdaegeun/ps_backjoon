#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int res;
    while(1)
    {
        getline(cin, str);
        if(str == ".")
            break;
        stack<int> st;
        res = 1;
        for(auto c : str)
        {
            if(c == '[' || c == '(')
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
            else if(c == ']')
            {
                if(!st.empty() && st.top() == '[')
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
            cout << "yes" << '\n';
        else   
            cout << "no" << '\n';
    }
}

// So when I die (the [first] I will see in (heaven) is a score list).
// [ first in ] ( first out ).
// Half Moon tonight (At least it is better than no Moon at all].
// A rope may form )( a trail in a maze.
// Help( I[m being held prisoner in a fortune cookie factory)].
// ([ (([( [ ] ) ( ) (( ))] )) ]).
//  .
// .