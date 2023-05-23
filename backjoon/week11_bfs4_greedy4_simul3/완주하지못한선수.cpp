#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> m_par; // name, cnt
    for(auto person: participant) {
        m_par[person]++;
    }
    for(auto name: completion) {
        m_par[name]--;
    }
    for(auto el:m_par) {
        if(el.second != 0)
            answer = el.first;
    }
    return answer;
}