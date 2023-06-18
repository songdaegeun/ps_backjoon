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

void counting_sort()
{
	// arr의 요소의 범위가 대략 1000만 이하일 때만 쓸 수 있다.
	int tmp[10] = {0,};
	for (int i = 0; i < LEN; i++)
	{
		tmp[arr[i]]++;
	}
	int idx = 0;
	for (int i = 0; i < 10; i++)
	{
		for(int j = 0; j < tmp[i]; j++)
		{
			arr[idx++] = i;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	counting_sort();
	for (int i = 0; i < LEN; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}