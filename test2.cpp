#include <string>
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
    while(i * i < num)
    {
        if(num % i == 0)
            return (0);
        i++;
    }
    return (1);
}

void brute(int depth, int num)
{
    if(depth == v.size())
    {
        int j = 0;
        cout << num << '\n';
        if(is_sosu(num))
            answer++;
        return;
    }
    num *= 10;
    brute(depth + 1, num);
    brute(depth + 1, num + v[depth]);
}


int solution(string numbers) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(auto ch : numbers)
    {
        v.push_back(ch - '0');
    }
    brute(0, 0);
    return answer;
}