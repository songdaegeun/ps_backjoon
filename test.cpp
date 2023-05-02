#include <iostream>
#include <vector>
using namespace std;

// int arr[10] = {8,2,85,89,564,4,1,854,41,41};
int arr[3] = {1, 3, 2};
int tmp[10];

int n, m;
vector<int> res_v;

void merge(int st, int en)
{
    int mid = (st + en) / 2;
    int idx_l = st;
    int idx_r = mid;

    for(int i = st; i < en; i++)
    {
        if(idx_l == mid)
            tmp[i] = arr[idx_r++];
        else if(idx_r == en)
            tmp[i] = arr[idx_l++];
        else if(arr[idx_l] <= arr[idx_r])
            tmp[i] = arr[idx_l++];
        else
            tmp[i] = arr[idx_r++];
    }
    for(int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en)
{
    if(st + 1 == en) // arr size : 1 
        return ;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    merge_sort(0, 3);

    for (int i = 0; i < 3; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    
}
