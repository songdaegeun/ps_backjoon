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
   
}

// 2 2
// 3 5
// 2 9