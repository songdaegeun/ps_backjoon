#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 만약, 수열의 두 수 X와 Y가 있을 때, X가 Y보다 수열에서 많이 등장하는 경우에는 X가 Y보다 앞에 있어야 한다. 만약, 등장하는 횟수가 같다면, 먼저 나온 것이 앞에 있어야 한다.
// 첫째 줄에 메시지의 길이 N과 C가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ C ≤ 1,000,000,000)
int n, c;
vector<pair<int, int>> v;

int cmp(pair<int, int> a, pair<int, int> b) {
    return (a.second > b.second);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> c;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        int flag = 0;
        cin >> x;
        for (int j = 0; j < v.size(); j++)
        {
            if(v[j].first == x) {
                v[j].second++;
                flag = 1;
            } 
        }
        if(!flag)        
            v.push_back({x, 1});
    }
    // 각 수와 빈도수를 pair로 v에 갖고 있는다. n <= 1000.
    // v를 빈도수 기준으로 내림차순 정렬한다. 빈도수 같으면 먼저 온게 앞서야하니까 stable sort로 정렬한다.
    // v를 순회하며 루프당 수를 빈도수만큼 출력한다.
    stable_sort(v.begin(), v.end(), cmp);
    for (auto el:v)
    {
        for (int i = 0; i < el.second; i++)
        {
            cout << el.first << ' ';
        }
    }
}


// 5 2
// 2 1 2 1 2