#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[8];
int visited[8];
int tmp[8];
int n, m;

void combi(int st, int depth)
{
	if(depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[tmp[i]] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = st; i < n; i++)
	{
		// if(!visited[i])
		// {
		// 	visited[i] = 1;
		tmp[depth] = i;
		combi(i, depth + 1);
		// 	visited[i] = 0;
		// }
	}
	
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    
    cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	combi(0, 0);

}

// 3 1
// 4 5 2