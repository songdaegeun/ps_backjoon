#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long arr[100005];

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
    
    sort(arr, arr + n, less<long long>());

    long long ans;
    int max_cnt = 0;
	int cnt = 0;
 
    cnt++;
	max_cnt = cnt;
	ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i - 1] == arr[i]) {
			cnt++;
		}
		else {
			if(max_cnt < cnt) {
				max_cnt = cnt;
				ans = arr[i - 1];
			}
			cnt = 1;
		}
    }
	if(max_cnt < cnt) {
		ans = arr[n - 1];
	}
    cout << ans;
}

// 5
// 1
// 2
// 1
// 2
// 1

// 4
// -2
// 4
// 1
// 1

// 5
// 1987654321
// 1987654321
// 1111111111
// 1111111111
// 4