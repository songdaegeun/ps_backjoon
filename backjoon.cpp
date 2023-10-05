#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int num, den;
	cin >> num >> den;
	while(!(num==0&&den==0)) {
		cout << num / den << ' ' << num % den << " / " << den << '\n'; 
		cin >> num >> den;
	}
}

// 27 12
// 2460000 98400
// 3 4000
// 0 0

// 2 3 / 12
// 25 0 / 98400
// 0 3 / 4000