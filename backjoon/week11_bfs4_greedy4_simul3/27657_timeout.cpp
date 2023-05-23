#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

class c_deque_info {
public:
	deque<pair<int,int>> a0;
	deque<pair<int,int>> a1;
};

void debug(c_deque_info &deque_info);
void a_b(c_deque_info &deque_info, int l);
void b_a(c_deque_info &deque_info, int l);
void rewind(c_deque_info &deque_info, int cnt_ro0, int cnt_ro1);
void command(c_deque_info &deque_info, string cmd, int from, int to = -1);
void reverse_rotate(c_deque_info &deque_info, int from, int to);
void rotate(c_deque_info &deque_info, int from, int to);
void push(c_deque_info &deque_info, int from, int to);

deque<string> ans;
vector<int> input_val;
vector<int> order_idx;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	c_deque_info deque_info;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		input_val.push_back(x);
	}
	
	vector<int> cmp_order(input_val.begin(), input_val.end());
	sort(cmp_order.begin(), cmp_order.end());
	for (int i = 0; i < input_val.size(); i++)
	{
		for (int j = 0; j < cmp_order.size(); j++)
		{
			if(cmp_order[j] == input_val[i])
				order_idx.push_back(j);
		}
	}
	for (int i = 0; i < input_val.size(); i++)
		deque_info.a0.push_back({input_val[i], order_idx[i]});
	a_b(deque_info, deque_info.a0.size());
	cout << ans.size() << '\n';
	for(auto el:ans) {
		cout << el << '\n';
	}
	// debug(deque_info);
}

void debug(c_deque_info &deque_info)
{
	cout << "a0: \n";
	for(auto el: deque_info.a0)
		cout << el.first << ' ';
	cout << '\n';
	for(auto el: deque_info.a0)
		cout << el.second << ' ';
	cout << '\n';
	cout << "a1: \n";
	for(auto el: deque_info.a1)
		cout << "["<< el.first << ":" << el.second << "]" << ' ';
	cout << '\n';
	cout << '\n';
}

void a_b(c_deque_info &deque_info, int l)
{
	int lp, rp;
	int cnt_ro0, cnt_pp, cnt_ro1;

	if(l <= 1)
		return ;
	if(l == 2)
	{
		command(deque_info, "PP", 0, 1);
		if(deque_info.a0.front().second < deque_info.a1.front().second) {
			command(deque_info, "RO", 0);
			command(deque_info, "PP", 1, 0);
			command(deque_info, "RRO", 0);
		}
		else {
			command(deque_info, "PP", 1, 0);
		}
		return ;
	}
	// lp = deque_info.a0.at(l / 3 - 1).second;
	// rp = deque_info.a0.at(2 * (l / 3 - 1)).second;
	lp = min(deque_info.a0.at(0).second, deque_info.a0.at(l - 1).second);
	rp = max(deque_info.a0.at(0).second, deque_info.a0.at(l - 1).second);
	cnt_ro0 = 0;
	cnt_pp = 0;
	cnt_ro1 = 0;
	for (int i = 0; i < l; i++)
	{
		int top = deque_info.a0.front().second;
		if(top >= rp) {
			command(deque_info, "RO", 0);
			cnt_ro0++;
		}
		else {
			command(deque_info, "PP", 0, 1);
			cnt_pp++;
			if (top >= lp) {
				command(deque_info, "RO", 1);
				cnt_ro1++;
			}
		}
	}
	rewind(deque_info, cnt_ro0, cnt_ro1);
	a_b(deque_info, cnt_ro0);
	b_a(deque_info, cnt_ro1);
	b_a(deque_info, cnt_pp - cnt_ro1);
}

void b_a(c_deque_info &deque_info, int l)
{
	int lp, rp;
	int cnt_ro0, cnt_pp, cnt_ro1;

	if (l == 0)
		return ;
	if(l == 1) {
		command(deque_info, "PP", 1, 0);
		return ;
	}
	if(l == 2) {
		command(deque_info, "PP", 1, 0);
		if(deque_info.a0.front().second < deque_info.a1.front().second) {
			command(deque_info, "RO", 0);
			command(deque_info, "PP", 1, 0);
			command(deque_info, "RRO", 0);
		}
		else {
			command(deque_info, "PP", 1, 0);
		}
		return ;
	}
	// lp = deque_info.a1.at(l / 3 - 1).second;
	// rp = deque_info.a1.at(2 * (l / 3) - 1).second;
	lp = min(deque_info.a1.at(0).second, deque_info.a1.at(l - 1).second);
	rp = max(deque_info.a1.at(0).second, deque_info.a1.at(l - 1).second);
	cnt_ro0 = 0;
	cnt_pp = 0;
	cnt_ro1 = 0;
	for (int i = 0; i < l; i++)
	{
		int top = deque_info.a1.front().second;
		if(top < lp) {
			command(deque_info, "RO", 1);
			cnt_ro1++;
		}
		else {
			command(deque_info, "PP", 1, 0);
			cnt_pp++;
			if (top < rp) {
				command(deque_info, "RO", 0);
				cnt_ro0++;
			}
		}
	}
	a_b(deque_info, cnt_pp - cnt_ro0);
	rewind(deque_info, cnt_ro0, cnt_ro1);
	a_b(deque_info, cnt_ro0);
	b_a(deque_info, cnt_ro1);
}

void rewind(c_deque_info &deque_info, int cnt_ro0, int cnt_ro1)
{
	for (int i = 0; i < min(cnt_ro0, cnt_ro1); i++) {
		command(deque_info, "RRO", 0);
		command(deque_info, "RRO", 1);
	}
	for (int i = 0; i < (cnt_ro0 - min(cnt_ro0, cnt_ro1)); i++)
		command(deque_info, "RRO", 0);
	for (int i = 0; i < (cnt_ro1 - min(cnt_ro0, cnt_ro1)); i++)
		command(deque_info, "RRO", 1);
}

void command(c_deque_info &deque_info, string cmd, int from, int to)
{
	string full_cmd;
	
	if(cmd == "PP") {
		push(deque_info, from, to);
		full_cmd = cmd + " " + to_string(from) + " " + to_string(to);
		ans.push_back(full_cmd);
		return ;
	}
	if(cmd == "RO")	{
		rotate(deque_info, from, to);
		full_cmd = cmd + " " + to_string(from);
		ans.push_back(full_cmd);
		return ;
	}
	if(cmd == "RRO") {
		reverse_rotate(deque_info, from, to);
		full_cmd = cmd + " " + to_string(from);
		ans.push_back(full_cmd);
		return ;
	}
	else
	{
		cout << "error!\n";
		return ;
	}
}

void reverse_rotate(c_deque_info &deque_info, int from, int to) 
{
	int tmp[2];
	if(from == 0 && to == -1) {
		tmp[0] = deque_info.a0.back().first;
		tmp[1] = deque_info.a0.back().second;
		deque_info.a0.pop_back();
		deque_info.a0.push_front({tmp[0], tmp[1]});
	}
	else if(from == 1 && to == -1) {
		tmp[0] = deque_info.a1.back().first;
		tmp[1] = deque_info.a1.back().second;
		deque_info.a1.pop_back();
		deque_info.a1.push_front({tmp[0], tmp[1]});
	}
}

void rotate(c_deque_info &deque_info, int from, int to) 
{
	int tmp[2];
	if(from == 0 && to == -1) {
		tmp[0] = deque_info.a0.front().first;
		tmp[1] = deque_info.a0.front().second;
		deque_info.a0.pop_front();
		deque_info.a0.push_back({tmp[0], tmp[1]});
	}
	else if(from == 1 && to == -1) {
		tmp[0] = deque_info.a1.front().first;
		tmp[1] = deque_info.a1.front().second;
		deque_info.a1.pop_front();
		deque_info.a1.push_back({tmp[0], tmp[1]});
	}
}

void push(c_deque_info &deque_info, int from, int to) 
{
	int tmp[2];
	
	if(from == 0 && to == 1) {
		tmp[0] = deque_info.a0.front().first;
		tmp[1] = deque_info.a0.front().second;
		deque_info.a0.pop_front();
		deque_info.a1.push_front({tmp[0], tmp[1]});
	}
	else if(from == 1 && to == 0) {
		tmp[0] = deque_info.a1.front().first;
		tmp[1] = deque_info.a1.front().second;
		deque_info.a1.pop_front();
		deque_info.a0.push_front({tmp[0], tmp[1]});
	}
	
}
// PP 0 1, RO 0, RRO 0

// 3
// 3 2 1

// 6
// RO 0
// PP 0 1
// PP 0 1
// RRO 1
// PP 1 0
// PP 1 0