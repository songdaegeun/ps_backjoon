#include <iostream>
#include <vector>
using namespace std;

int arr[10] = {8,2,85,89,564,4,1,854,41,41};
int tmp[10];
int n, m;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int q_sort(int st, int en)
{
    int l_idx = st;
    int r_idx = en;
    int pivot = arr[st];
    while(1)
    {
        while(l_idx <= r_idx && pivot >= arr[l_idx])
            l_idx++;
        while(l_idx <= r_idx && pivot < arr[r_idx])
            r_idx--;
        if(l_idx > r_idx) break;
        swap(&arr[l_idx], &arr[r_idx]);
    }
    swap(&arr[r_idx], &arr[st]);

    return (r_idx);
}

void quick_sort(int st, int en)
{
    // 구간의 길이가 1이하일 때
    if(en <= st + 1)
        return;
    int mid = q_sort(st, en);
    quick_sort(st, mid);
    quick_sort(mid + 1, en);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    quick_sort(0, 10-1);

    for (int i = 0; i < 10; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}
