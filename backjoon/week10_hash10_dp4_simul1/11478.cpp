#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
string str;
unordered_set<string> res;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str;
    for (int i = 1; i <= str.length(); i++)
    {
        for (int j = 0; j < str.length() - (i - 1); j++)
        {
            res.insert(str.substr(j, i));
        }
    }
    cout << res.size() << '\n';
}

// ababc