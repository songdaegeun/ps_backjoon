#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    int p_len = players.size();
    int c_len = callings.size();
    map<string, int> m1;
    
    for(int i = 0; i < p_len; i++){
        m1[players[i]] = i;
    }
    for(int i = 0; i < c_len; i++){
        string tmp;
        int idx = m1[callings[i]];
        
        tmp =  players[idx - 1];
        players[idx - 1] = players[idx];
        players[idx] = tmp;
        
        m1[callings[i]]--;
        m1[tmp]++;
    }
    for(int i = 0; i < p_len; i++) {
        answer.push_back(players[i]);
    }
    return answer;
}