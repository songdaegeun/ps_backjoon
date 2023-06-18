#include <string>
#include <vector>
#include <iostream>
using namespace std;


int rule1[5] = {1,2,3,4,5};
int rule2[8] = {2,1,2,3,2,4,2,5};
int rule3[10] = {3,3,1,1,2,2,4,4,5,5};
int cnt1 = 0;
int cnt2 = 0;
int cnt3 = 0;

vector<int> solution(vector<int> answers) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> answer;
    for(int i = 0; i < answers.size(); i++){
        int idx1 = i % 5;
        int idx2 = i % 8;
        int idx3 = i % 10;
        cnt1 += (answers[i] == rule1[idx1]);
        cnt2 += (answers[i] == rule2[idx2]);
        cnt3 += (answers[i] == rule3[idx3]);
    }
    int max = 0;
    if(cnt1 > max)
        max = cnt1;
    if(cnt2 > max)
        max = cnt2;
    if(cnt3 > max)
        max = cnt3;
    
    if(max == cnt1)
        answer.push_back(1);
    if(max == cnt2)
        answer.push_back(2);
    if(max == cnt3)
        answer.push_back(3);
    return answer;
}