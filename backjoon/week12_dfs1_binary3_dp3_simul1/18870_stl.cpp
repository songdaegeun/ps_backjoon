#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000001];
vector<int> uni_vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        uni_vec.push_back(arr[i]);
    }
    sort(uni_vec.begin(), uni_vec.end());
    uni_vec.erase(unique(uni_vec.begin(), uni_vec.end()), uni_vec.end());
    for (int i = 0; i < n; i++)
    {
        cout << lower_bound(uni_vec.begin(), uni_vec.end(), arr[i]) - uni_vec.begin() << ' ';
    }

    
}

// 1,000,000
// 정렬: nlogn
// 중복제거: n


// 5
// 2 4 -10 4 -9