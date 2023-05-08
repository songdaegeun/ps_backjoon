#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[100001];
long long cnt[100001];

int compare(long long a, long long b) {

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

    // 가장 많이 가지고 있는 정수를 출력.
    // 가장 많이 가지고 있는 정수가 같다면, 작은 것을 출력.
    // arr의 요소가 long long으로 들어오므로 counting sort는 불가.
    
    // n개의 요소를 내림차순 정렬한다.
    sort(arr, arr + n, greater<>());
    // arr를 순회하면서 해당 요소가 이전 요소와 같을 경우, idx번째의 cnt를 올린다.
    // idx는 0부터 시작하고, 요소가 달라질때마다 변한다.
    // idx가 가리키는 arr의 요소는 내림차순이다.
    // cnt를 내림차순 정렬한다.
    // idx가 가리키는 arr의 요소는 오름차순이 된다.

    int idx = 0;
    cnt[idx]++;
    for (int i = 1; i < n; i++)
    {
        if(arr[i - 1] == arr[i])
            cnt[idx]++;
        else
            idx++;
    }
    
}

// 5
// 1
// 2
// 1
// 2
// 1