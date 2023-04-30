#include <iostream>
using namespace std;

int ft_pow(long long a, long long b, long long c) 
{
	if(b == 1)
		return (a % c);
	long long rem = ft_pow(a, b / 2, c);
	rem = rem * rem % c;
	if(b % 2 == 0) return (rem);
	return  rem * a % c;
}
// R(1) = a % c
// R(2k) = R(R(k)^2) <- O(1)
// R(2k + 1) = R(R(k)^2 * a) <- O(1)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	long long a, b, c;
	cin >> a >> b >> c;
	cout << ft_pow(a, b, c);
}

// 10 11 12