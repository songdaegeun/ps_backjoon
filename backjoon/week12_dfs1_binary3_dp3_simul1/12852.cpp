#include <iostream>
using namespace std;

int d[1000001];
int pre[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    d[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + 1;
        pre[i] = i - 1;
        if(i%2 == 0) {
            if(d[i] > d[i/2] + 1) {
                d[i] = d[i/2] + 1;
                pre[i] = i/2;
            }
        }
        if(i%3 == 0) {
            if(d[i] > d[i/3] + 1) {
                d[i] = d[i/3] + 1;
                pre[i] = i/3;
            }
        }
    }
    cout << d[n] << '\n';
    int idx = n;
    while(1) {
        cout << idx << ' ';
        if(idx == 1)
            break;
        idx = pre[idx];
    }    
}

// d[x] = 1로만드는 연산의 최소 횟수

// X가 3으로 나누어 떨어지면, 3으로 나눈다.
// X가 2로 나누어 떨어지면, 2로 나눈다.
// 1을 뺀다.
// 정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.
// 연산을 사용하는 횟수의 최솟값을 출력하시오.