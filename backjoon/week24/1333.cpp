#include <iostream>
using namespace std;

int n,l,d;
int song[4000];
int bell[4000];

void disp_map() {
	for (int i = 0; i <= n*l+(n-1)*5+d; i++) {
		cout << song[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i <= n*l+(n-1)*5+d; i++) {
		cout << bell[i] << ' ';
	}
	cout << '\n';

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> l >> d;
	int tm = 0;
	int prev = tm;
	int idx;
	int local_n;
	
	idx = 0;
	local_n = n;
	while(local_n--) {
		for (int i = 0; i < l; i++)
			song[idx + i] = 1;
		idx+=(l+5);
	}
	idx = 0;
	local_n = n;
	while(idx < 4000) {
		bell[idx] = 1;
		idx+=d;
	}
	// disp_map();
	// 20*180+19*5+20
	int i = 0;
	while(1)
	{
		if(song[i] == 0 && bell[i] == 1) {
			cout << i << '\n';
			return (0);
		}
		i++;
	}
	
	

	
}

// 2 2 3
// 9