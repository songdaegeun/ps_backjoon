#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> group_key_mem;
    unordered_map<string, vector<string>> group_map;
    for (int i = 0; i < n; i++)
    {
        string group, mem_num, mem_name;
        cin >> group >> mem_num;
        for (int j = 0; j < stoi(mem_num); j++)
        {
            cin >> mem_name;
            group_map[group].push_back(mem_name);
            group_key_mem[mem_name] = group;
        }
        sort(group_map[group].begin(), group_map[group].end());
    }

    for (int i = 0; i < m; i++)
    {
        string query;
        int category;
        cin >> query >> category;
        if(category)
        {
            // group이름 출력
            cout << group_key_mem[query] << '\n';
        }
        else
        {
            // group에 포함된 member전부 출력
            for(auto mem: group_map[query]) {
                cout << mem << '\n';
            }
        }
    }
    
}

// 3 4
// twice
// 9
// jihyo
// dahyeon
// mina
// momo
// chaeyoung
// jeongyeon
// tzuyu
// sana
// nayeon
// blackpink
// 4
// jisu
// lisa
// rose
// jenny
// redvelvet
// 5
// wendy
// irene
// seulgi
// yeri
// joy
// sana
// 1
// wendy
// 1
// twice
// 0
// rose
// 1