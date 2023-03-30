#include <iostream>
#include <queue>
using namespace std;

void solve(int n);
// 10845
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<int> q;
    string str;
    int data;
    int n;
    cin >> n; 
    while(n--)
    {
        cin >> str;
        if(str == "push")
        {
            cin >> data;
            q.push(data);
        }
        else if(str == "pop")
        {
            if(!q.empty())
            {
                cout << q.front() << "\n";
                q.pop();
            }
            else
                cout << "-1\n";
        }
        else if(str == "front")
        {
            if(!q.empty())
               cout << q.front() << "\n";
            else
                cout << "-1\n";
        }
        else if(str == "back")
        {
            if(!q.empty())
               cout << q.back() << "\n";
            else
                cout << "-1\n";
        }
        else if(str == "size")
        {
            cout << q.size() << "\n";
        }
        else if(str == "empty")
        {
            if(q.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
}