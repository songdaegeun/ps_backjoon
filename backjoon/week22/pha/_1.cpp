#include<iostream>
#include<string>
#include <stdlib.h>
using namespace std;

int solution(string p, string s)
{
    int size = p.size();
    int sum = 0;

    for(int i = 0; i < size; i++) {
        int diff = abs(p[i] - s[i]);
        if (diff >= 5)
            diff = 10 - diff;
        cout << diff << ' ';
        sum += diff;
    }
    return sum;
}
