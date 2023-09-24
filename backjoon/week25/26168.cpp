#include <iostream>
#include <algorithm>
using namespace std;

long long n,m;
long long a[100001];

// 9,223,372,036,854,775,807

long long ft_lower_bound(long long st, long long en, long long target) {
	long long mid;
	while (st <= en) {
		mid = (st + en)/2;
        if (a[mid] >= target)
            en = mid - 1;
        else
            st = mid + 1;
	}
    return st;
}

long long ft_upper_bound(long long st, long long en, long long target) {
	long long mid;
	while (st <= en) {
		mid = (st + en)/2;
        if (a[mid] > target)
            en = mid - 1;
        else
            st = mid + 1;
	}
    return st;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
	for (long long i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	long long type, bound_1, bound_2;

	for (long long i = 0; i < m; i++)
	{
		long long cnt = 0;
		cin >> type;
		// 1 k: 배열 A의 원소 중 bound_1보다 크거나 같은 원소의 개수를 출력한다.
		if(type == 1) {
			cin >> bound_1;
			// for (long long j = n-1; j >= 0; j--)
			// {
			// 	if(a[j] < bound_1) {
			// 		break;
			// 	}
			// 	cnt++;
			// }
			// long long ret = lower_bound(a, a+n, bound_1) - a;
			long long ret = ft_lower_bound(0, n-1, bound_1);

			cnt = n-ret;
		}
		// 2 k: 배열 A의 원소 중 bound_1보다 큰 원소의 개수를 출력한다.
		else if(type == 2) {
			cin >> bound_1;
			// for (long long j = n-1; j >= 0; j--)
			// {
			// 	if(a[j] <= bound_1) {
			// 		break;
			// 	}
			// 	cnt++;
			// }
			// long long ret = ft_upper_bound(a, a+n, bound_1) - a;
			long long ret = ft_upper_bound(0, n-1, bound_1);
			cnt = n-ret;
		}
		// 3 i j: 배열 A의 원소 중 bound_1보다 크거나 같고 bound_2보다 작거나 같은 원소의 개수를 출력한다.
		else if(type == 3) {
			cin >> bound_1 >> bound_2;
			long long st = 0;
			long long en = n-1;
			// while(st <= en && a[st] < bound_1) {
			// 	st++;
			// }
			// long long ret1 = lower_bound(a, a+n, bound_1) - a;
			long long ret1 = ft_lower_bound(0, n-1, bound_1);
			cnt = n-ret1;
			// while(en >= st && a[en] > bound_2) {
			// 	en--;
			// }
			// long long ret2 = upper_bound(a, a+n, bound_2) - a;
			long long ret2 = ft_upper_bound(0, n-1, bound_2);
			cnt -= (n-ret2);
		}
		cout << cnt << '\n';
	}
}
// O(N^2)

// 8 7
// 2 2 5 5 5 10 15 20
// 1 1
// 1 2
// 1 3
// 1 5
// 1 30
// 2 1
// 2 2