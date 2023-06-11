#include <iostream>
using namespace std;

int arr[4000001];

int is_sosu(int x)
{
    if(x < 2)
        return (0);
    int i = 2;
    while(i * i <= x)
    {
        if (x % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int sol = 0;

    //1부터 n이하까지 소수들의 배열 arr를 만든다.
    // arr의 부분합이 n이 되는 경우를 cnt.
    int idx = 0;
    for (int i = 2; i <= n; i++)
    {
        if(is_sosu(i))
            arr[idx++] = i;
    }
    
    int en = 0;
    int sum = arr[0];
    for (int st = 0; st < idx; st++)
    {
        while(en < idx && sum < n)
        {
            en++;
            if(en != idx)
                sum += arr[en];
        }
        if(en == idx) break;
        if(sum == n){
            sol++;
        }
        sum -= arr[st];
    }
    cout << sol << '\n';
}

// 첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.

