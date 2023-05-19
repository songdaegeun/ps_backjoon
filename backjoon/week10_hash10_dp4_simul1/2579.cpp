#include <iostream>
using namespace std;

int d[301][3];
int step[301];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> step[i];
	}
	d[1][1] = step[1];
	d[1][2] = 0;
	d[2][1] = step[2];
	d[2][2] = step[1] + step[2];
	
	for (int i = 3; i <= n; i++)
	{
		d[i][2] = d[i - 1][1] + step[i];
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + step[i];
	}
	cout << max(d[n][1], d[n][2]) << '\n';
	
}