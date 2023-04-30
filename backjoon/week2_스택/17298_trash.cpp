#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[1000001];
    memset(arr, 0, sizeof(int) * 1000001);
    int n, i, el;
    cin >> n;
    i = 1;
    while(i <= n)
    {
        cin >> el;
        arr[i] = el;
        i++;
    }
    i = 1;
    while(i <= n)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(arr[i] < arr[j])
            {
                cout << arr[j] << ' ';
                break;
            }
            if(j == n)
                cout << -1 << ' ';
        }
        if(i == n)
            cout << -1 << ' ';
        i++;
    }


}