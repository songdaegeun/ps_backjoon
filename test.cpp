#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if(arr[i] > arr[j])
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ' ';
	}	
}
