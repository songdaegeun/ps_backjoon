#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, s, min;
    min = 100000000;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int en = 0;
    int sum = 0;
    int flag = 0;
    for (int st = 0; st < n; st++)
    {
        if(st > 0)
            sum -= arr[st - 1];
        while(en < n && sum < s)
        {
            sum += arr[en];
            en++;
        }
        if(sum < s) break;
        flag = 1;
        if(min > (en - st))
            min = en - st;
    }
    if(flag == 0)
        cout << 0 << '\n';
    else
        cout << min << '\n';
}

// 10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

// 10 15
// 5 1 3 5 10 7 4 9 2 8