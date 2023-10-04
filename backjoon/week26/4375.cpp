#include <iostream>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int cnt;
	while(cin >> n) {
		int cmp = 1;
		cnt = 1;
		while(1) {
			if (cmp%n==0)
			{
				break;
			}
			else {
				cnt++;
				cmp = cmp*10+1;
				cmp %= n;
			}
		}
		cout << cnt << '\n';
	}
}

// 3
// 7
// 9901