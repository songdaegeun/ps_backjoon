#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1])
            swap(&sizes[i][0], &sizes[i][1]);
    }
    int max_r = 0;
    int max_c = 0;
    for(int i = 0; i < sizes.size(); i++){
        max_r = max(max_r, sizes[i][0]);
        max_c = max(max_c, sizes[i][1]);
    }
    cout << max_r << ' ' << max_c << '\n';
    answer = max_r * max_c;
    
    return answer;
}