#include <iostream>
#include <list>
using namespace std;

int main()
{
	string str;
	cin >> str;
	list<char> lt;
	for(auto c: str) lt.push_back(c);
	list<char>::iterator cur = lt.end();
	// cout << *cur;
	int n;
	cin >> n;
	while(n--)
    {
		char cmd;
		cin >> cmd;
		if(cmd == 'P')
        {
			char text_ch;
			cin >> text_ch;
			lt.insert(cur, text_ch);
		}
        else if(cmd == 'L')
        {
            if(cur != lt.begin())
                cur--;
        }
        else if(cmd == 'D')
        {
            if(cur != lt.end())
                cur++;
        }
        else if(cmd == 'B')
        {
			if(cur != lt.begin())
			{
				cur--;
				cur = lt.erase(cur);
			}
        }
	}
	for (auto c: lt) cout << c;
}