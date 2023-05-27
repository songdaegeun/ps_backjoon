#include <iostream>
#include <algorithm>
using namespace std;

int rope[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> rope[i];
	}
	sort(rope, rope + n, greater<int>());
	int max_w = 0;
	for (int k = 1; k <= n; k++)
	{
		int allow_w = rope[k - 1] * k;
		if(max_w < allow_w)
			max_w = allow_w;
	}
	cout << max_w;
	
	// 병렬로 들 수 있는 최대 중량 출력.
	// 모든 로프를 사용해야 할 필요는 없음.
	
	// 병렬:
	// rope의 갯수를 k, 중량을 w이라고 했을때, 
	// 각 rope에 w/k의 하중이 걸린다.
	// 이 때 0~k-1의 i에 대해 rope[i] >= w/k이면 w를 들 수 있다.
	// 즉, 이 경우 w의 최대값은 n * min(rope[i])이다.

	// 로프의 일부만써도 되므로 k를 1부터 n까지 두고 나온 w의 값중 최대값을 출력하면 됨. <- O(N)
	// rope[i]의 최소값을 구하는 과정을 O(n)으로 따로 잡아버리면, k의 각 값에 대해 최소값을 찾아야하므로 O(N^2)이다.
	// n =10^5, n^2은 대략 10s니까 시간초과다.
	// 로프의 일부를 선택할때는 주어진 rope[i] 중 항상 허용하중이 큰 순서대로 선택해야 w의 최대값을 구할 수 있다.
	// 그래서 미리 rope를 내림차순으로 정렬해둔다. 
	// 내림차순이므로 현재 선택되는 요소는 처음부터 선택된 요소까지의 범위중에 항상 최소값이 되므로 최소값을 찾는 과정이 필요없다. <- O(N)

}

// 2
// 10
// 15