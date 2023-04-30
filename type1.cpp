#include <iostream>
#include <vector>
#define NUM 9
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	vector<int> v;
	int arr[NUM] = {3, 2, 4, 4, 2, 5, 2, 5, 5};
	int visited[NUM] = {0,};
	for (int i = 0; i < NUM; i++)
	{
		int cnt = 0;
		for (int j = 0; j < NUM; j++)
		{
			if (arr[i] == arr[j] && visited[j] == 0)
			{
				visited[j] = 1;
				cnt++;
			}
		}
		if(cnt > 1)
			v.push_back(cnt);
	}
	if(v.empty())
		cout << -1;
	for(auto a:v)
	{
		cout << a << ' ';
	}
}
