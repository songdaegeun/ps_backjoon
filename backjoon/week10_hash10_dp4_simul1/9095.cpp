#include <iostream>
using namespace std;

int d[11];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i <= 11; i++)
	{
		d[i] = d[i - 3] + d[i - 2] + d[i - 1];
	}
	// dp table을 먼저 만들어놓으면 됨. (tc loop안에 둘 필요없음)
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}

// 3
// 4
// 7
// 10