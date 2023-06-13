#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<int> q;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    int cnt = 0;
    cout << '<';
    while(!q.empty()) {
        int num = q.front();
        q.pop();
        if(cnt != k - 1) {
            q.push(num);
        }
        else {
            cout << num;
            if(!q.empty())
                cout << ", ";
            else
                cout << '>';
        }
        cnt++; 
        cnt %= k; 
    }
    
}

// 7 3