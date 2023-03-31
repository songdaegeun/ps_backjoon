#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<int> q;
    int n, i, res;
    cin >> n;
    i = 1; 
    while(i <= n)
    {
        q.push(i);
        i++;
    }
    while(q.size() > 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
}
