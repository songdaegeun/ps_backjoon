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
    int i, el, num, height, width;
    long long max, space;
    max = -1;
    int arr[100000];
    memset(arr, 0, sizeof(int) * 100000);
    
    stack<int> s;
    i = 0;
    while(i < n)
    {
        cin >> el;
        arr[i] = el;
        i++;
    }
	i = 0;
    while(i < n)
    {
		while(s.size() && arr[s.top()] > arr[i])
		{
			height = arr[s.top()];
			s.pop();
			width = i;
			if(s.size())
				width = i - s.top() - 1;
			if(max < (long long)height * width)
				max = (long long)height * width;
		}
		s.push(i);
        i++;
}
	while(s.size())
	{
		height = arr[s.top()];
		s.pop();
		width = n;
		if(s.size())
			width = n - s.top() - 1;
		if(max < (long long)height * width)
			max = (long long)height * width;
	}
    cout << max << '\n';
}