#include <string>
#include <vector>
#include <iostream>
#include <cstring>
// build_frame {x,y,a,b} : a[0:기둥, 1:보], b[0:삭제, 1:설치]
// answer {x,y,a} : a[0:기둥, 1:보]

using namespace std;
int map[101][101][2];
vector<vector<int>> answer;
int g_n;

int can_set(int x, int y, int a) {
// 1. 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
// 2. 보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
    // x,y,a
    if(a == 0) {
//         기둥
        if(y == 0 || (x - 1 >= 0 && map[x - 1][y][1] == 1) \
          || (map[x][y][1] == 1) \
          || (y - 1 >= 0 && map[x][y - 1][0] == 1) ) {
            return (1);
        }
    }
    else {
//         보
        if((y - 1 >= 0 && map[x][y - 1][0] == 1) || \
           (x + 1 <= g_n && y - 1 >= 0 && map[x + 1][y - 1][0] == 1) || \
           ((x - 1 >= 0 && map[x - 1][y][1] == 1) && \
           (x + 1 <= g_n && map[x + 1][y][1] == 1) )) {
            return (1);
        }
    }
    return (0);
}

int is_stable() {
//     map을 순회하면서 map의 요소를 다시한번 놓아봄.
    for(int i = 0; i <= g_n; i++) {
        for(int j = 0; j <= g_n; j++) {
            for(int k = 0; k < 2; k++) {
                if(map[i][j][k] == 1 && !can_set(i, j, k)) {
                    // cout << "here:"<< i << j << '\n';
                    return (0);
                }
            }
        }
    }
    return (1);
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    g_n = n;
    
    for(auto el: build_frame) {
        // 순회하며 설치 or 삭제
        if(el[3] == 1) {
//             설치
            if(can_set(el[0], el[1], el[2])) {
                map[el[0]][el[1]][el[2]] = 1;
            }
        }
        else {
//             삭제
            map[el[0]][el[1]][el[2]] = 0;
            // cout << el[0] << el[1] << '\n';
            if(!is_stable()) {
                map[el[0]][el[1]][el[2]] = 1;
            }
        }
    }
    // answer 작성
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k < 2; k++) {
                if(map[i][j][k] == 1) {
                    answer.push_back({i,j,k});
                }
            }
        }
    }
    // 기둥과 보가 둘다 설치되는 경우를 고려해야함.
    
    // // debug
    // for(auto el:answer) {
    //     cout << el[0] << el[1] << el[2] << '\n';
    // }
    
    return answer;
}