#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v;
int answer = 0;

int is_sosu(int num)
{
    if(num < 2)
        return (0);
    int i = 2;
    while(i * i <= num)
    {
        if(num % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int is_used[8];
int temp_num[8];
vector<int> sosu_vec;

void permu(int depth, int m)
{
    if(depth == m)
    {
        int num = 0;
        for(int i = 0; i < m; i++)
        {
            num *= 10;
            num += temp_num[i];
        }
        sosu_vec.push_back(num);
        return ;
    }
    for(int i = 0; i < v.size(); i++)
    {
        if(!is_used[i])
        {
            is_used[i] = 1;
            temp_num[depth] = v[i];
            permu(depth + 1, m);
            is_used[i] = 0;
        }
    }
}


int solution(string numbers) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(auto ch : numbers)
    {
        v.push_back(ch - '0');
    }
    for(int i = 1; i <= v.size(); i++)
    {
        permu(0, i);
    }
    // sosu_vec 중복제거
    sort(sosu_vec.begin(), sosu_vec.end());
    sosu_vec.erase(unique(sosu_vec.begin(), sosu_vec.end()), sosu_vec.end()); 
    for(auto num : sosu_vec)
    {
        if(is_sosu(num))
        {
            cout << num << '\n';
            answer++;
        }
            
    }

    return answer;
}