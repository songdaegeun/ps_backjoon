// bubble_sort: o
// select_sort: o
// insert_sort: o
// merge_sort: o
// quick_sort: index error

#include <iostream>
#define LEN 10
using namespace std;

int arr[LEN] = {5, 3, 2, 6, 1, 7, 3, 3, 5, 9};
int tmp[LEN];

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort()
{
	for (int i = 1; i < LEN; i++)
	{
		for (int j = 0; j < LEN - i; j++)
		{
			if(arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}	
}

void select_sort()
{
	// min
	// for (int i = 0; i < LEN - 1; i++)
	// {
	// 	int min_idx = i;
	// 	for (int j = i + 1; j < LEN; j++)
	// 	{
	// 		if(arr[min_idx] > arr[j]) min_idx = j;
	// 	}
	// 	swap(&arr[min_idx], &arr[i]);
	// }
	// max
	for (int i = LEN - 1; i > 0; i--)
	{
		int max_idx = i;
		for (int j = 0; j < max_idx; j++)
		{
			if(arr[max_idx] < arr[j]) max_idx = j;
		}
		swap(&arr[max_idx], &arr[i]);
	}
}

void insert_sort()
{
	for (int i = 1; i < LEN; i++)
	{
		int j;
		int key = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if(arr[j] > key) arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = key;
	}
}

void merge(int st, int en)
{
	int mid = (st + en) / 2;
	int l_idx = st;
	int r_idx = mid;
	
	for (int i = st; i < en; i++)
	{
		if(l_idx == mid) tmp[i] = arr[r_idx++];
		else if(r_idx == en) tmp[i] = arr[l_idx++];
		else if(arr[l_idx] <= arr[r_idx]) tmp[i] = arr[l_idx++];
		else
			tmp[i] = arr[r_idx++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en)
{
	if(en == st + 1)
		return ;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}

int quick(int st, int en)
{
	int pivot = arr[st];
	int l_idx = st + 1; // st로 해도 됨. 하지만 pivot은 비교대상이 아니므로 st + 1이 더 좋음.
	int r_idx = en - 1;
	while(1)
	{
		// pivot보다 큰 순간의 l_idx결정.
		while(l_idx <= r_idx && pivot >= arr[l_idx]) 
			l_idx++;
		// pivot보다 작은 순간의 r_idx결정.
		while(l_idx <= r_idx && pivot <= arr[r_idx])
			r_idx--;
		if(l_idx > r_idx)
			break;	
		swap(&arr[l_idx], &arr[r_idx]);
	}
	// pivot보다 작은걸 pivot과 swap(stable sort)
	swap(&arr[r_idx], &arr[st]);
	// r_idx의 위치에 pivot이 존재.
	return (r_idx);
}

void quick_sort(int st, int en)
{
	if(en <= st + 1) // quick_sort(mid + 1, en);이 call되면 en == st인 경우도 발생가능.
		return ;
	int mid = quick(st, en);
	quick_sort(st, mid);
	quick_sort(mid + 1, en);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	bubble_sort();
	// select_sort();
	// insert_sort();
	// merge_sort(0, LEN);
	// quick_sort(0, LEN);

	for (int i = 0; i < LEN; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}