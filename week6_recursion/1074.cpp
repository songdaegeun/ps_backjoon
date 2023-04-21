#include <iostream>
using namespace std;

int map_search(int n, int r, int c)
{
	if(n == 0)
		return 0;
	int half_size = (1 << (n - 1));
	if(r < half_size && c < half_size) return (map_search(n - 1, r, c));
	else if(r < half_size && c >= half_size) return (half_size * half_size + map_search(n - 1, r, c - half_size));
	else if(r >= half_size && c < half_size) return (2 * half_size * half_size + map_search(n - 1, r - half_size, c));
	else return (3 * half_size * half_size + map_search(n - 1, r - half_size, c - half_size));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n, r, c;
	cin >> n >> r >> c;
	cout << map_search(n, r, c);
}

// 2 3 1