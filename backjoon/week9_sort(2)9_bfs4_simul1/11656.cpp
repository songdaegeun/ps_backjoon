#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans; 

void make_sub(string str) {
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        // ans.push_back(str);
        // str.erase(str.begin(), str.begin() + 1);
        string tmp = str.substr(i);
        ans.push_back(tmp);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;

    make_sub(str);
    sort(ans.begin(), ans.end());
    for(auto str: ans){
        cout << str << '\n';
    }
}
// 첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 1,000보다 작거나 같다.


// baekjoon