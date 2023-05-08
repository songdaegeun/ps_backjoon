#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long arr[100001];
long long cnt[100001];


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
    
    // n개의 요소를 오름차순 정렬한다.
    sort(arr, arr + n, less<long long>());
    // arr를 순회하면서 해당 요소가 이전 요소와 같을 경우, idx번째의 cnt를 올린다.
    // idx는 0부터 시작하고, 요소가 달라질때마다 변한다.
    // idx가 가리키는 arr의 요소는 오름차순이다.
    // cnt를 순회해서 max값을 찾는다.
    // 다시 cnt를 max값과 같은 요소들을 ans_vec에 넣는다.
    // ans_vec[0]을 출력한다.

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    int idx = 0;
    cnt[idx]++;
    for (int i = 1; i < n; i++)
    {
        if(arr[i - 1] != arr[i])
        {
            idx++;
        }
        cnt[idx]++;
    }
    int max = 0;
    for (int i = 0; i <= idx; i++) {
        if(max < cnt[i]) max = cnt[i];
    }
    vector<int> ans_v;
    for (int i = 0; i <= idx; i++) {
        if(max == cnt[i]) ans_v.push_back(cnt[i]);
    }
    cout << ans_v[0];
}

// 5
// 1
// 2
// 1
// 2
// 1