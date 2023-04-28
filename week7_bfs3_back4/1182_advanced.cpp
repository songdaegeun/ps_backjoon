#include <iostream>
using namespace std;

int n,s;
int arr[23];
int sum[23];
int cnt;

void binary_choice(int depth, int tot)
{
	if(depth == n)
	{
		if(tot == s)
			cnt++;
		return ;
	}	
    binary_choice(depth + 1, tot);
	binary_choice(depth + 1, tot + arr[depth]);
    
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
    binary_choice(0, 0);	// 집합 arr내의 모든 부분집합을 탐색
	if(s == 0) cnt--;	// 공집합인 경우 tot이 0이 되는데, s == tot이 되지만 count하면 안되므로 s == 0 이면 를 제외해야 함.
    cout << cnt;
}

// 5 0
// -7 -3 -2 5 8