#include <iostream>
using namespace std;

int t;
int total, day_per_month, day_per_week;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> t;
	int line;
	for (int i = 0; i < t; i++)
	{
		line = 0;
		cin >> total >> day_per_month >> day_per_week;
		int j = 0;
		int tmp_day_per_month = day_per_month;
		while (j < total)
		{
			// 1. day_per_month <= day_per_week
			if(tmp_day_per_month <= day_per_week) {
				if(j == (total - 1))
					line++;
				else
					line+=2;
				tmp_day_per_month = day_per_month - (day_per_week - tmp_day_per_month%day_per_week);
			}
			// 2. day_per_month%day_per_week == 0
			else if(tmp_day_per_month%day_per_week == 0) {
				line+= tmp_day_per_month/day_per_week;
			}
			// 3. day_per_month%day_per_week != 0
			else {
				line+= tmp_day_per_month/day_per_week;
				tmp_day_per_month = day_per_month - tmp_day_per_month%day_per_week;
			}
			cout << "tmp_day_per_month:" << tmp_day_per_month << " line:" << line << '\n';
			j++;
		}

		cout << "Case #" << i+1 << ": " << line << '\n';
	}
	
	
}

// 5
// 1 3 5
// 2 3 5
// 3 3 5
// 4 3 5
// 5 3 5

// 1
// 2 3 5