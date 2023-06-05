#include <iostream>
using namespace std;

int arr[100001];
int d[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        d[i] = d[i - 1] + arr[i];
    }
        
    for (int i = 0; i < m; i++) {
        int st, en;
        cin >> st >> en;
        // 합 출력
        cout << d[en] - d[st - 1] << '\n';
    }
}
// prefix sum.
// arr[st] + ... + arr[en]
// = (arr[1] + ... + arr[en]]) - (arr[1] + ... + arr[st - 1])

// 5 3
// 5 4 3 2 1
// 1 3
// 2 4
// 5 5