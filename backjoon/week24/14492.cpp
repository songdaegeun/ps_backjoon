#include <iostream>
using namespace std;

int n;
int arr1[301][301];
int arr2[301][301];
int arr3[301][301];

void get_arr(int (arr)[301][301]) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{	
			cin >> arr[i][j];
		}
	}
}

void disp_arr(int (arr)[301][301])
{
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{	
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	get_arr(arr1);
	get_arr(arr2);
	// disp_arr(arr1);
	// disp_arr(arr2);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{	
				arr3[i][j] += arr1[i][k]*arr2[k][j]; 
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(arr3[i][j] != 0)
				cnt++;
		}
	}
	// disp_arr(arr3);
	cout << cnt;
}

// cij = (ai1∧b1j)∨(ai2∧b2j)∨...∨(ain∧bnj)

// 3
// 1 1 0
// 0 1 0
// 0 0 1
// 1 0 0
// 1 1 1
// 0 0 1