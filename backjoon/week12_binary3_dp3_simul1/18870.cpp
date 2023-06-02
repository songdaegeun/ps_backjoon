#include <iostream>
#include <algorithm>
using namespace std;

int tmp_arr[1000001];
int arr[1000001];
int back_arr[1000001];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp_arr[i];
        back_arr[i] = tmp_arr[i];
    }
    sort(tmp_arr, tmp_arr + n);
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if(i == 0 || tmp_arr[i - 1] != tmp_arr[i])
            arr[idx++] = tmp_arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << lower_bound(arr, arr + idx, back_arr[i]) - arr << ' ';
    }

    
}

// 1,000,000
// 정렬: nlogn
// 중복제거: n


// 5
// 2 4 -10 4 -9