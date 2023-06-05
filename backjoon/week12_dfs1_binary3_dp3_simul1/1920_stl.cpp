#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int num;
int n,m;

void binary(int st, int en) {
    if(st > en) {
        cout << 0 << '\n';
        return ;
    }
    int mid = (st + en) / 2;
    if(arr[mid] == num) {
        cout << 1 << '\n';
        return ;
    }
    else if(num < arr[mid]) {
        binary(0, mid - 1);
    }
    else {
        binary(mid + 1, n - 1);
    }
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
        cin >> num;
        cout << binary_search(arr, arr + n, num) << '\n';
    }
    
    
}

// 5
// 4 1 5 2 3
// 5
// 1 3 7 9 5