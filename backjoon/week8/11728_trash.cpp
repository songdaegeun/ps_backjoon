#include <iostream>
#include <vector>
using namespace std;

int arr_n[1000001];
int arr_m[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n, m;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr_n[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr_m[i];
    }
    int idx_n = 0;
    int idx_m = 0;
    vector<int> res_v;
    while(!(idx_n >= n || idx_m >= m))
    {
        if(arr_n[idx_n] < arr_m[idx_m])
        {
            res_v.push_back(arr_n[idx_n++]);
        }
        else if(arr_n[idx_n] > arr_m[idx_m])
        {
            res_v.push_back(arr_m[idx_m++]);
        }
        else
        {
            res_v.push_back(arr_n[idx_n++]);
            res_v.push_back(arr_m[idx_m++]);
        }
        if(idx_n >= n)
        {
            while(idx_m < m)
                res_v.push_back(arr_m[idx_m++]);
        }
        else if(idx_m >= m)
        {
            while(idx_n < n)
                res_v.push_back(arr_n[idx_n++]);
        }
    }
    for(auto num: res_v)
    {
        cout << num << ' ';
    }
}

// 2 2
// 3 5
// 2 9