#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,a,b;
int cost_a[100002];
int cost_b[100002];

void disp_cost() {
	for (int i = 0; i < n; i++)
	{
		cout << cost_a[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		cout << cost_b[i] << ' ';
	}
	cout << '\n';
}

int cmp(pair<int,int> &a, pair<int,int>&b ) {
	if(a.second > b.second)
		return (1);
	else
		return (0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	vector<int> cost_min;
	vector<pair<int,int>> risk_vec;
	cin >> n >> a >> b;
	int cost[2];
	for (int i = 0; i < n; i++)
	{
		cin >> cost[0] >> cost[1];
		cost_a[i] = cost[0];
		cost_b[i] = cost[1];
		if(cost_a[i] < cost_b[i]) {
			cost_min.push_back(cost_a[i]);
		}
		else {
			cost_min.push_back(cost_b[i]);
		}
	}
	// disp_cost();

	for(int i = 0; i < cost_min.size(); i++) {
		if(cost_min[i] == cost_a[i]) {
			risk_vec.push_back({i, cost_b[i] - cost_min[i]});
		}
		else {
			risk_vec.push_back({i, cost_a[i] - cost_min[i]});
		}
	}
	sort(risk_vec.begin(), risk_vec.end(), cmp);
	
	// for (int i = 0; i < risk_vec.size(); i++)
	// {
	// 	cout << risk_vec[i].second << ' ';
	// }
	// cout << '\n';
	// for (int i = 0; i < risk_vec.size(); i++)
	// {
	// 	cout << risk_vec[i].first << ' ';
	// }
	// cout << '\n';

	// risk_vec는 오답으로 손해볼 수 있는 가격들의 정보임.
	// 가격손해 정보기준 내림차순임.
	// 순회 당 합리적인 소비를 하면서 해당 가게를 방문한 횟수를 체크.
	// 횟수를 채우면 나머지는 그냥 나머지 가게를 방문하면 됨.
	int cnt_a = 0;
	int cnt_b = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		if(cost_min[risk_vec[i].first] == cost_a[risk_vec[i].first]) {
			cnt_a++;
		}
		else {
			cnt_b++;
		}
		sum += cost_min[risk_vec[i].first];
		if(cnt_a == a) {
			if(cnt_a == n)
			{
				sum -= cost_min[risk_vec[i].first];
				sum += cost_b[risk_vec[i].first];
			}
			else {
				for (int j = i+1; j < n; j++)
				{
					sum += cost_b[risk_vec[j].first];
				}
			}
			break;
		}
		else if(cnt_b == b) {
			if(cnt_b == n)
			{
				sum -= cost_min[risk_vec[i].first];
				sum += cost_a[risk_vec[i].first];
			}
			else {
				for (int j = i+1; j < n; j++)
				{
					sum += cost_a[risk_vec[j].first];
				}
			}
			break;
		}
	}
	cout << sum << '\n';
}

// 5 2 3
// 4 6
// 7 2
// 5 5
// 3 6
// 10 9