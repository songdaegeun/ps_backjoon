#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> relation[2000];
int visited[2000];
int flag;

void dfs(int node, int depth) {
    if(depth == 4) {
        flag = 1;
        return ;
    }
    visited[node] = 1;
    for (int i = 0; i < relation[node].size(); i++)
    {
        int next = relation[node][i];
        if(visited[next] || flag) continue;
        dfs(next, depth + 1);
    }
    visited[node] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    vector<pair<int,int>> data;
    // sort -> nlogn
    // search -> n
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        relation[a].push_back(b);
        relation[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i, 0); 
        if (flag == 1){
            cout << 1 << '\n';
            return (0);
        }
    }
    cout << 0 << '\n';        
}

// 5 4
// 0 1
// 1 2
// 2 3
// 3 4