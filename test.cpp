#include <iostream>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
  return a.first > b.first;
}

pair<int,int> arr[] = {{1,1}, {2,2}};
int n = sizeof(arr) / sizeof(pair<int,int>);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    sort(arr, arr + n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].second << ' ';
    }
    cout << '\n';
    
// 출력 결과: 9 6 5 5 5 4 3 3 2 1 1

}