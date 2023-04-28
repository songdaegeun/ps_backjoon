#include <iostream>
using namespace std;

int n,s;
int arr[23];
int sum[23];
int cnt;

void combi(int start_i, int depth, int m)
{
    if(depth == m)
    {
        int total = 0;
        for (int i = 0; i < m; i++)
            total += sum[i];
        if(total == s)
            cnt++;
        return ;
    }
    for (int i = start_i; i < n; i++)
    {
        sum[depth] = arr[i];
        combi(i + 1, depth + 1, m);
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        combi(0, 0, i);
    }
    cout << cnt;
}

// 5 0
// -7 -3 -2 5 8