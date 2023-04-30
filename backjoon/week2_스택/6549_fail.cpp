#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

void solve(int n);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    while(1)
    {
        cin >> n; 
        if(n == 0) break; 
        solve(n);
    }
}

void solve(int n)
{
    int i, el, num;
    long long max, space;
    max = -1;
    int arr[100000];
    memset(arr, 0, sizeof(int) * 100000);
    
    stack< pair<int,int> > s;
    i = 0;
    while(i < n)
    {
        cin >> el;
        arr[i] = el;
        i++;
    }
    i = n - 1;
    while(i > -1)
    {
        num = 1;
        while(s.size() && s.top().first >= arr[i]) //순증가
        {
            num += s.top().second;
            s.pop();
        }
		space = (long long)num * arr[i]; // 우측 방향
        if(max < space) max = space;
        s.push(make_pair(arr[i], num));
        i--;
    }
	num = 0;
    while(s.size())
    {
		num += s.top().second;
        space = (long long)num * s.top().first;
		// cout << '[' << space << ']'; 
        if(max < space) max = space;
        s.pop();
    }
    cout << max << '\n';
}

// 8
// 20
// 20
// 1
// 1
// 8
// 4000
// 5000000000
// 0
// 14
// 12
// 1250000000
// 625000000
// 2437
// 1275   << @
// 10 593 532 425 137 647 231 84 698 421 378
// sol: 425*3 = 1275
// my: 532*2 = 1064

// 15