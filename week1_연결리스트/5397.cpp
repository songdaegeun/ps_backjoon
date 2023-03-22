#include <iostream>
#include <list>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
    {
        list<char> lt;
	    list<char>::iterator cur = lt.end();
        string str;
	    cin >> str;  
        int i = 0;
        while(str[i]){  
            char ch;
            ch = str[i];
            if(ch == '<')
            {
                if(cur != lt.begin())
                    cur--;
            }
            else if(ch == '>')
            {
                if(cur != lt.end())
                    cur++;
            }
            else if(ch == '-')
            {
                if(cur != lt.begin())
                {
                    cur--;
                    cur = lt.erase(cur);
                }
            }
            else
            {
                lt.insert(cur, ch);
            }
            i++;
        }
        for (auto c: lt) cout << c;
        cout << "\n";
    }
}
// <<BP<A>>Cd-
// ThIsIsS3Cr3t