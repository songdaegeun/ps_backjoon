#include <iostream>
using namespace std;

char src[100001];
char dst[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int tc;
	cin >> tc;
	while (tc--)
	{
		int size = 0;
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			cin >> src[i];
		}
		for (int i = 0; i < size; i++)
		{
			cin >> dst[i];
		}
		int cnt = 0;
		int b_cnt = 0;
		int w_cnt = 0;
		
		for (int i = 0; i < size; i++)
		{
			if(src[i] != dst[i]) {
				cnt++;
				if(src[i] == 'W')
					w_cnt++;
				else
					b_cnt++;
			}
		}
		// cout << cnt << ' ' << w_cnt << ' ' << b_cnt << "\n";
		cout << cnt - min(w_cnt, b_cnt) << "\n";
		
	}
	
}



// 다른갯수 - (다른것들중)couple 개수
// 4 - 1 = 3
// 0010000
// 0101010


// 3
// 5
// WBBWW
// WBWBW
// 7
// BBBBBBB
// BWBWBWB
// 4
// WWBB
// BBWB

// 1100
// 0010

// 3 - 1 = 2