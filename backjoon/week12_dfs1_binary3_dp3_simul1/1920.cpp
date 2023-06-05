#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int num;
int n,m;

int binary(int target) {
    int st = 0;
    int en = n - 1;
    while(st <= en) {
        int mid = (st + en) / 2;
        if(arr[mid] < target)
            st = mid + 1;
        else if(target < arr[mid])
            en = mid - 1;
        else
            return (1);
    }
    return (0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int flag = 0;
        cin >> num;
        // arr내에 num이 존재한다면 1 return.
        cout << binary(num) << '\n';
    }
    
    
}

// 5
// 4 1 5 2 3
// 5
// 1 3 7 9 5