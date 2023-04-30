#include <iostream>
using namespace std;

int n, m;
int arr[9];

void combi(int start_i, int depth)
{
	if(depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = start_i; i <= n; i++)
	{
		arr[depth] = i;
		combi(i + 1, depth + 1);
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> m;
	combi(1, 0);
}
