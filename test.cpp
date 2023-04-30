#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v;

int is_sosu(int num)
{
    if(num < 2)
        return (0);
    int i = 2;
    while(i * i < num)
    {
        if(num % i == 0)
            return (0);
        i++;
    }
    return (1);
}


int solution(string numbers) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int answer = 0;
    for(auto ch : numbers)
    {
        v.push_back(ch - '0');
    }
    vector<int> idx_v;
    for(int i = 0; i < v.size(); i++)
        idx_v.push_back(i);
    do
    {
        
        int num = 0;
        for(int i = 0; i < idx_v.size(); i++)
        {
            cout << idx_v[i] << ' ';
            num += v[idx_v[i]];
        }
        cout << '\n';
        if(is_sosu(num))
            answer++;
    }while(next_permutation(idx_v.begin(), idx_v.end()));
    
    return answer;
}