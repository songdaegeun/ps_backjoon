#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(pair<string,int> a, pair<string,int> b) {
    return (a.second < b.second);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, l;
    cin >> k >> l;
    unordered_map<string, int> map; // string은 학번, int는 순서.
    for (int i = 0; i < l; i++)
    {
        string str;
        cin >> str;
        // 한번 왔었던 str일 경우, 기존의 str을 삭제하고 자료구조에 추가.
        // 순서는 유지되어야 함.
        if(map.find(str) != map.end())
            map.erase(str);
        map[str] = i;
    }
    vector<pair<string,int>> v(map.begin(), map.end());
    sort(v.begin(), v.end(), cmp);
    int idx = 0;
    for(auto el:v) {
        cout << el.first << '\n';
        idx++;
        if(idx == k)
            break;
    }
}

// 3 8
// 20103324
// 20133221
// 20133221
// 20093778
// 20140101
// 01234567
// 20093778
// 20103325