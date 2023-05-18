#include <iostream>
#include <unordered_map>
using namespace std;

long long n;
int p, q;
unordered_map<long long,long long> serial;

long long find_serial(long long n) {
	if (n == 0) return 1;				// base condition
	if (serial[n]) return serial[n];	// base condition
	// serial[n]이 존재하지 않는 경우
	serial[n] = find_serial(n / p) + find_serial(n / q);
	// memoization
	return (serial[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> p >> q;

	cout << find_serial(n) << '\n';
}

// 7 2 3