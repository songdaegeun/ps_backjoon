#include <iostream>
#include <algorithm>
using namespace std;

int arr[13];
int tmp[13];
int k;

void combi()
{
	for (int i = 0; i < k; i++) (i < 6)? tmp[i] = 0 : tmp[i] = 1;
	do
	{
		for (int i = 0; i < k; i++)
		{
			if(!tmp[i])
			{
				cout << arr[i] << ' ';
			}
		}
		cout << '\n';
	} while (next_permutation(tmp, tmp + k));
	
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	while(1)
	{
		cin >> k;
		if(k == 0)
			break;
		for (int i = 0; i < k; i++)
			cin >> arr[i];
		combi();
		cout << '\n';
	}
}

// 7 1 2 3 4 5 6 7
// 8 1 2 3 5 8 13 21 34
// 0