#include <iostream>
using namespace std;

int cost[3][102];
int a, b, c;
int last_en, min_en;

void disp_cost()
{
	cout << '\n';
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i <= last_en + 1; i++)
		{
			cout << cost[j][i] << ' ';
		}
		cout << '\n';
	}	
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> a >> b >> c;
	int st, en;
	last_en = -1;
	min_en = 999;
	for (int i = 0; i < 3; i++)
	{
		cin >> st >> en;
		if(last_en < en)
			last_en = en;
		if(min_en > st)
			min_en = st;
		for (int j = st; j < en; j++)
		{
			cost[i][j] = 1;
		}
	}
	// disp_cost();
	int num = 0;
	int sum = 0;
	for (int idx = min_en; idx <= last_en; idx++)
	{
		num = 0;
		for (int i = 0; i < 3; i++)
			num += cost[i][idx];
		if(num == 1) {
			sum += a;
		}
		else if(num == 2) {
			sum += 2*b;
		}
		else if(num == 3) {
			sum += 3*c;
		}
		// cout << num << '\n';
	}		
	cout << sum << '\n';
}

// 5 3 1
// 1 6
// 3 5
// 2 8