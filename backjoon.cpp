#include <iostream>
#include <algorithm>

using namespace std;

int k;
int var[14];
int mask[14];

int main() {
	while(1) {
		cin >> k;
		if(k == 0)
			break;
		for (int i = 0; i < k; i++)
		{
			cin >> var[i];
		}
		fill(mask+6,mask+k ,1);
		do {
			for (int i = 0; i < k; i++)
			{
				if(!mask[i]) {
					cout << var[i] << ' ';
				}
			}
			cout << '\n';
		} while(next_permutation(mask, mask+k));
		cout << '\n';
	}
	
	

	return (0);
}

// 7 1 2 3 4 5 6 7
// 8 1 2 3 5 8 13 21 34
// 0
