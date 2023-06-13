#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	list<char> li;
	string str;
	cin >> str;
	for(auto el:str) {
		li.push_back(el);
	}
	int n;
	cin >> n;
	list<char>::iterator it = li.end();
	while(n--)
	{
		char cmd;
		cin >> cmd;
		if(cmd == 'L')
		{
			if(it != li.begin())
				it--;

		}
		else if (cmd == 'D')
		{
			if(it != li.end())
				it++;
		}
		else if (cmd == 'B')
		{
			if(it != li.begin()) {
				it--;
				it = li.erase(it);
			}
		}
		else if (cmd == 'P')
		{
			char ch;
			cin >> ch;
			li.insert(it, ch);
		}
	}
	for(auto el: li)
	{
		cout << el;
	}
	cout << '\n';
}