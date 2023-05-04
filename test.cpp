#include <iostream>
#define LEN 10
using namespace std;

int arr[LEN] = {5, 3, 2, 6, 1, 7, 3, 3, 5, 9};

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	for (int i = 0; i < LEN; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}