#include <iostream>
using namespace std;
int arr[9];
int chk[9];

void permut(int n, int m, int depth)
{
    if(depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return ;
    }
        

    for (int i = 1; i <= n; i++)
    {
        if(chk[i] == 0)
        {
            chk[i] = 1;
            arr[depth] = i;
            permut(n, m, depth + 1);
            chk[i] = 0;
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int n, m;
    cin >> n >> m;
    permut(n,m, 0);
	
}
// 3 1