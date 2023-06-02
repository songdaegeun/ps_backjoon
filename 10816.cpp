#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[500001];

int lower_idx(int target) {
    int st = 0;
    int en = n;
    while(st < en) {
        int mid = (st + en) / 2;
        if(arr[mid] < target)
            st = mid + 1;
        else if(target <= arr[mid])
            en = mid;
    }
    return (st);
}

int upper_idx(int target) {
    int st = 0;
    int en = n;
    while(st < en) {
        int mid = (st + en) / 2;
        if(arr[mid] <= target)
            st = mid + 1;
        else if(target < arr[mid])
            en = mid;
    }
    return (st);
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
        int num;
        cin >> num;
        int r_idx = lower_idx(num);
        int u_idx = upper_idx(num);
        
        cout << u_idx - r_idx << ' ';
    }
    
}