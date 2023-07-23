#include <iostream>
using namespace std;

int n,m,k;
int A[11][11];		// 양분
int age[11][11];	// 나이

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	while (m--)
	{
		int x,y,z;
		cin >> x >> y >> z;
		age[x][y] = z;
	}
	
}

// 5 2 3
// 2 3 2 3 2
// 2 3 2 3 2
// 2 3 2 3 2
// 2 3 2 3 2
// 2 3 2 3 2
// 2 1 3
// 3 2 3