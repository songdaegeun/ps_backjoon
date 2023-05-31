#include <iostream>
using namespace std;

int d[2][41];
// d[0]: i에 대해 0이 출력되는 횟수
// d[1]: i에 대해 1이 출력되는 횟수

// d[0][i]과 d[1][i]는 0과 1 각각의 출력횟수이므로 독립적임.
// d[0][i]는 d[0][i - 1] + d[0][i - 2]
// d[1][i]는 d[1][i - 1] + d[1][i - 2]
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[0][0] = 1;
    d[1][1] = 1;
    for (int i = 2; i <= 40; i++)
    {
       d[0][i] = d[0][i - 1] + d[0][i - 2];
       d[1][i] = d[1][i - 1] + d[1][i - 2];
    }
    
    int tc;
    cin >> tc;
    while(tc--) {
        int num;
        cin >> num;
        cout << d[0][num] << ' ' << d[1][num] << '\n';
    }
}
