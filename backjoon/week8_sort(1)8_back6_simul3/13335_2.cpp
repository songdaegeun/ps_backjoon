#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int n, w, l, run_time, on_load;
queue<int> truck_queue;
queue<int> bridge_queue;

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
	while(1)
	{
		if(bridge_queue.size() == w) {
			on_load -= bridge_queue.front();
			bridge_queue.pop();
		}
		if(!truck_queue.empty()) {
			if((on_load + truck_queue.front()) > l)
				bridge_queue.push(0);
			else {
				bridge_queue.push(truck_queue.front());
				on_load += truck_queue.front();
				truck_queue.pop();
			}
		}
		else
			bridge_queue.push(0);
		
		run_time++;
		if(truck_queue.empty() && on_load == 0)
			break;
	}
	cout << run_time;
}

// 4 2 10
// 7 4 5 6