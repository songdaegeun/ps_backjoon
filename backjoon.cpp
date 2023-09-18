#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int ans[300001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	double cutoff_d = n*0.15;
	int cutoff_i = (int)round(cutoff_d);

	for (int i = 0; i < n; i++)
	{
		cin >> ans[i];
	}
	sort(ans, ans+n);
	double avg = 0.0;
	
	for (int i = cutoff_i; i < n-cutoff_i; i++)
	{
		avg += ans[i];
	}
	if(n) {
		avg = avg/(n-2*cutoff_i);
		cout << (int)round(avg) << '\n';
	}
	else {
		cout << 0 << '\n';
	}	
}

// 4
// 1
// 2
// 3
// 4