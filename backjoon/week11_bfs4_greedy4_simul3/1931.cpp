#include <algorithm>
#include <iostream>
using namespace std;

int n;
pair<int,int> arr[100001];

int cmp(pair<int,int> a, pair<int,int>b){
	if(a.second != b.second)
		return (a.second < b.second);
	else
		return (a.first < b.first);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;	
	}
	sort(arr, arr + n, cmp);
	int s, e;
	e = -1;
	int cnt = 0;
	int i = 0;
	while(1) {
		for (; i < n; i++)
		{
			if(e <= arr[i].first) {
				s = arr[i].first;
				break;
			}
		}
		if(i == n) break;
		for (; i < n; i++)
		{
			if(s <= arr[i].second) {
				e = arr[i].second;
				i++;
				cnt++;
				break;
			}
		}	
		if(i == n) break;	
	}
	cout << cnt << '\n';
	// 제일 빨리끝나는 회의들을 우선해서 처리하면 된다.
	// 즉, e가 작은 것들을 우선해서 cnt한다.
	// e를 오름차순 정렬. e같으면 s를 오름차순 정렬.
	// 이 상태에서, 아래의 절차를 따른다.
	// 맨 첫번째 요소의 회의의 first와 second를 s,e로 갖는다.
	// first중에 e보다 같거나 큰 것중 가장 작은 것을 s로 선택한다.
	// second중에 s보다 같거나 큰 것중 가장 작은 것을 e로 선택한다.

	// 반복.
}

// 11
// 1 4
// 2 4
// 2 8
// 3 5
// 0 6
// 5 7
// 3 8
// 5 9
// 6 10
// 8 11
// 8 12
// 2 13
// 12 14