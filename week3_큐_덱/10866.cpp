#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<int> deq;
    string str;
    int n, data;

    cin >> n;
    while(n--)
    {
        cin >> str;
        if(str == "push_front")
        {
            cin >> data;
            deq.push_front(data);
        }
        else if(str == "push_back")
        {
            cin >> data;
            deq.push_back(data);
        }
        else if(str == "pop_front")
        {
            if (!deq.empty())
            {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
            else
                cout << -1 << '\n';
            
        }
        else if(str == "pop_back")
        {
            if (!deq.empty())
            {
                cout << deq.back() << '\n';
                deq.pop_back();
            }            else
                cout << -1 << '\n';
        }
        else if(str == "size")
        {
            cout << deq.size() << '\n';
        }
        else if(str == "empty")
        {
            cout << deq.empty() << '\n';
        }
        else if(str == "front")
        {
            if (!deq.empty())
                cout << deq.front() << '\n';
            else
                cout << -1 << '\n';
        }
        else if(str == "back")
        {
            if (!deq.empty())
                cout << deq.back() << '\n';
            else
                cout << -1 << '\n';
        }
    }
}