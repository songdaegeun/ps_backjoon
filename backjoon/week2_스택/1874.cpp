#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int n;
    cin >> n;
    int arr[n + 1];
    memset(arr, 0, n + 1);
    int i, j;
    i = n;
    while(i != 0)
    {
        int el;
        cin >> el;
        arr[i--] = el;
    }
    
    i = 1;
    j = n;
    while(i <= n)
    {
        s.push(i);
        while (s.size() && j > 0 && s.top() == arr[j])
        {
            s.pop();
            j--;
        }
        i++;
    }
    if (j == 0)
    {
        i = 1;
        j = n;
        while(i <= n)
        {
            s.push(i);
            cout << '+' << '\n';
            while (s.size() && j > 0 && s.top() == arr[j])
            {
                s.pop();
                cout << '-' << '\n';
                j--;
            }
            i++;
        }
    }
    else
        cout << "NO\n";
}
