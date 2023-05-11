#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<string>> ans;

int comp(vector<string> a, vector<string> b) {
    if(a[1] != b[1]) {
        return (stoi(a[1]) > stoi(b[1]));
    }
    else if(a[2] != b[2]) {
        return (stoi(a[2]) < stoi(b[2]));
    }
    else if(a[3] != b[3]) {
        return (stoi(a[3]) > stoi(b[3]));
    }
    else {
        return (a[0] < b[0]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<string> data;
        string name, guk, young, su;
        cin >> name >> guk >> young >> su;
        data.push_back(name);
        data.push_back(guk);
        data.push_back(young);
        data.push_back(su);
        ans.push_back(data);
    }
    sort(ans.begin(), ans.end(), comp);
    for(auto el:ans) {
        cout << el[0] << '\n';
    }

}

// 국어 점수가 감소하는 순서로
// 국어 점수가 같으면 영어 점수가 증가하는 순서로
// 국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
// 모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
