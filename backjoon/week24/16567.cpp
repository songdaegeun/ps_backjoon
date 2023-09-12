#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int n,m;
int load[1000001];
int cnt = 0;
// int pre;
// int pre_idx;

void disp_map()
{
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		cout << load[i] << ' '; 
	}
	cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> load[i];
		if (load[i] && !load[i - 1])
      		cnt++;
	}
	cin.ignore();
	// pre_idx = 0;
	// pre = load[pre_idx];
	while (m--)
	{
		string trial;
		// cin.ignore();
		getline(cin, trial);
		if(trial[0] == '0') {
			cout << cnt << '\n';
		}
		// 1 i
		else {
			int idx = stoi(trial.substr(2));
			if(load[idx])
				continue;
			load[idx] = 1;
			if (load[idx - 1] && load[idx + 1])
				cnt--;
			else if (!load[idx - 1] && !load[idx + 1])
				cnt++;
		}
		
		
	}
	
	

}

// 5 9
// 0 0 0 0 0
// 0
// 1 4
// 0
// 1 4
// 0
// 1 2
// 0
// 1 3
// 0