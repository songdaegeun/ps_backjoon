#include <iostream>
#include <cmath>
using namespace std;

int arr[2][7];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int s, y;
		cin >> s >> y;
		arr[s][y]++;
	}
	int num = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			num += ceil((double)arr[i][j] / k);
		}
	}
	cout << num << '\n';
}