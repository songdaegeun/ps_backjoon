#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	stack<char> st1;
	stack<char> st2;
	string str;
	cin >> str;
	for(auto el:str) {
		st1.push(el);
	}
	int n;
	cin >> n;
	while(n--)
	{
		char cmd;
		cin >> cmd;
		if(cmd == 'L')
		{
			if(!st1.empty()) {
				st2.push(st1.top()); st1.pop();
			}
				
		}
		else if (cmd == 'D')
		{
			if(!st2.empty()) {
				st1.push(st2.top()); st2.pop();
			}
				
		}
		else if (cmd == 'B')
		{
			if(!st1.empty())
				st1.pop();
		}
		else if (cmd == 'P')
		{
			char ch;
			cin >> ch;
			st1.push(ch);
		}
	}
	while(!st1.empty()) {
		st2.push(st1.top()); st1.pop();
	}
	while(!st2.empty()) {
		cout << st2.top();
		st2.pop();
	}
	cout << '\n';
}