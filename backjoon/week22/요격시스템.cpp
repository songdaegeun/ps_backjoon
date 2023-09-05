#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int cmp(vector<int> a, vector<int> b)
{
    return (a[1] < b[1]);
}

int solution(vector<vector<int>> targets) {
    // 공통되는 x가 존재하는 요소끼리 그룹핑해야한다.
    // 개구간 (start, end)에서 end순서대로 정렬한다.
    // 기준 구간의 end보다 다음 구간의 start가 작다면, cnt하지않는다.
    // 기준 구간의 end보다 다음 구간의 start가 크거나 같다면, cnt한다.
    sort(targets.begin(), targets.end(), cmp);
    int cnt = 0;
    int flag = 1;
    vector<int> base = targets[0];
    for(auto el: targets) {
        if(base[1] <= el[0] || flag == 1) {
            cnt++;
            base = el;
            flag = 0;
        }
    }
    
    return cnt;
}