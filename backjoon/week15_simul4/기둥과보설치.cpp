#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    // 모든 순서의 투입 인원에 대해, 
    // 가능한 모든 출발점에서 마지막점까지 시계로 도는 경우 중에서 최소 투입인원 결정.  
    int w_size = weak.size();
    for(int i = 0; i < w_size - 1; i++) {
        weak.push_back(weak[i] + n);
    }
    sort(dist.begin(), dist.end());
    int min_prove = 9;
    do {
        for(int i = 0; i < w_size; i++) {
            int st = weak[i];
            int en = weak[i + w_size - 1];
            
            int cnt = 0;
            for(auto prove:dist) {
                st += prove;
                cnt++;
                if(st >= en) {
                    if(min_prove > cnt) {
                        min_prove = cnt;
                    }
                    break;
                }
                for(int j = i + 1; j < i + w_size; j++) {
                    // st지점 반올림.
                    if(weak[j] > st) {
                        st = weak[j];
                        break;
                    }
                }
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));
    if(min_prove == 9)
        return (-1);
    return min_prove;
}