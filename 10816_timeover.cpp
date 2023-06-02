#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[500001];

int binary(int target) {
    int st = 0;
    int en = n - 1;
    int cnt = 0;
    while(st <= en) {
        int mid = (st + en) / 2;
        if(arr[mid] < target)
            st = mid + 1;
        else if(target < arr[mid])
            en = mid - 1;
        else
            return (mid);
    }
    return (-1);
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
        int idx = binary(num);
        int cnt = 0;
        if(idx != -1) {
            int i = idx;
            while(arr[i] == num && i < n) {
                cnt++;
                i++;
            }
            i = idx - 1;
            while(arr[i] == num && i >= 0) {
                cnt++;
                i--;
            }
        }
        cout << cnt << ' ';
    }
    
}