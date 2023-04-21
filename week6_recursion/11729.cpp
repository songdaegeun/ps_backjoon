#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int start, int dist)
{
	if (n == 1)
	{
		cout << start << ' ' << dist << '\n';
		return ;
	}
	hanoi(n - 1, start, 6 - (start + dist));
	cout << start << ' ' << dist << '\n';
	hanoi(n - 1, 6 - (start + dist), dist);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n;
	cin >> n;
	// tower(n) 1 -> 3은
	// tower(n - 1) 1 -> 2, 
	// base_panel 1 -> 3,  <- O(1)
	// tower(n - 1) 2 -> 3으로 달성할 수 있다.

	cout << (int)pow(2, n) - 1 << '\n';
	hanoi(n, 1, 3);
}
