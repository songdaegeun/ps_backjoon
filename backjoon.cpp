#include <iostream>
using namespace std;

int d[41];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[0] = 0;
    d[1] = 1;
    for (int i = 2; i <= 40; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }
    
    int num;
    cin >> num;
    cout << d[num] << '\n';

}
