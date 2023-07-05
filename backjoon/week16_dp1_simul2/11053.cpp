#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v;
int d[1001] = {1,} ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    fill(d, d + n, 1);
    // d[i]는 0부터 i까지 가장 긴 증가하는 부분수열
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(v[j] < v[i]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }
    cout << *max_element(d, d + n) << '\n';

}

// 6
// 10 20 10 30 20 50


