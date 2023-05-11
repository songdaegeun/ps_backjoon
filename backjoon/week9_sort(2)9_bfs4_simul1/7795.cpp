#include <iostream>
#include <algorithm>
using namespace std;

int arr_a[20001];
int arr_b[20001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr_a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> arr_b[i];
        }
        // a가 b보다 큰 쌍의 개수를 구한다.
        // 1. arr_a를 순회하며 각 루프에서 요소가 arr_b보다 큰 경우를 count. -> O(NM) n,m<20,000 , 4s(1억/s)니까 timer over.
        // 2. arr_b를 오름차순정렬한다.
        // arr_a를 순회하며 각 루프에서 arr_b를 순회하며 arr_a의 요소 <= arr_b의 요소 인 순간 break. -> arr_a의 모든 요소가 arr_b의 모든 요소를 먹을 수 있으면 O(NM);
        // 3. 종류a, 종류b를 pair<값, a_b구분자>로 같은  arr에 두고 오름차순 정렬한 뒤 arr_b일때 cnt하다가 arr_a일때 먹히는 식으로 arr를 돌면 O(N + M),
        // 4. algorithm헤더파일에 선언된 upper_bound함수는 인수로 {arr, arr +n, 비교값}을 받고 arr의 요소 중 비교값을 초과하는 요소가 처음 나타난 주소를 반환.(없으면 last(개구간)반환)
        // 이를 이용해서 arr_a를 오름차순 정렬해놓고 종류b의 값을 받을때마다 그 값을 upper_bound에 넣고 arr_a에서 비교해서 초과값이 있는 위치를 찾은 뒤 그걸 이용해서 종류b를 먹을 수있는 쌍만큼 ans에 더함. 
        // 이 방법은 m번의 루프에서 한번만에 일어나는 이분 탐색임. -> O(N + M). uppper_bound의 시간 복잡도는 무시했음.
        sort(arr_b, arr_b + m);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int a = arr_a[i];
            int j = 0;
            while(j < m && a > arr_b[j]) {
                cnt++;
                j++;
            }
        }
        cout << cnt << '\n';
    }

}

// 2
// 5 3
// 8 1 7 3 1
// 3 6 1
// 3 4
// 2 13 7
// 103 11 290 215