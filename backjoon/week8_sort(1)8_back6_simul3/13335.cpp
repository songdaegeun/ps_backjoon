#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int n, w, l, run_time;
queue<int> truck_queue;
deque<pair<int,int>> bridge; // weight, distance

int bridge_weight()
{
	int total = 0;
	for (int i = 0; i < bridge.size(); i++)
	{
		total += bridge[i].first;
	}
	return (total);
}
void bridge_distance_decrease()
{
	int size = bridge.size();
	int flag = 0;
	for (int i = 0; i < size; i++)
	{
		bridge[i].second--;
		if(bridge[i].second == 0) // 맨 앞의 트럭 한번만 발생가능.
			flag = 1;
	}
	// 다리 위의 트럭이 가야할 거리가 0이 되면 다리를 나간다.
	if(flag == 1)
		bridge.pop_front();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> n >> w >> l;
	for (int i = 0; i < n; i++)
	{
		int weight;
		cin >> weight;
		truck_queue.push(weight);
	}
	while(!truck_queue.empty() || !bridge.empty())
	{
		// 다리 위의 모든 트럭이 가야할 거리는 1 줄어든다.(= 단위시간동안 단위거리만큼 전진)
		bridge_distance_decrease();
		if(!truck_queue.empty())
		{
			int truck = truck_queue.front(); 
			int on_bridge_weight = bridge_weight();
			// 다리 위에 w개의 트럭이 존재할 수 있고, 동시에 다리 위 트럭의 무게 합은 l보다 작거나 같아야한다.
			if(on_bridge_weight + truck <= l && bridge.size() + 1 <= w)
			{
				truck_queue.pop();
				bridge.push_back({truck, w});
			}
		}
		// 트럭이 올라갔다면, 올라간 직후 그 트럭이 앞으로 가야할 거리는 w이다.
		run_time++;
	}
	cout << run_time;
}

// 4 2 10
// 7 4 5 6