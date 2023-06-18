#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
// 종류별 의상개수 = [종류]++로 parsing.
// 경우의 수 계산
    unordered_map<string, int> kind_cloth;
    for(auto v:clothes) {
        kind_cloth[v[1]]++;
    }
    int sol = 1;
    for(auto el:kind_cloth) {
        sol *= (el.second + 1);
    }
    sol--;
    return sol;
}