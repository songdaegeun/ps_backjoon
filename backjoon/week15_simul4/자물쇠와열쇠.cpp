#include <string>
#include <vector>

using namespace std;
int m,n,map_size;

int match_key(int y, int x, vector<vector<int>> &map, vector<vector<int>> &key) {
    int flag = 1;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            map[i+y][j+x] += key[i][j];
        }
    }
    
     for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i+m-1][j+m-1] != 1) {
                flag = 0;
                break;
            }
        }
     }
    
    // restore
     for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            map[i+y][j+x] -= key[i][j];
        }
    }
    
    return (flag);
}

void rotate(vector<vector<int>> &key) {
    vector<vector<int>> tmp_key(m,vector<int> (m,0));
    // backup
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            tmp_key[i][j] = key[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            key[j][m-1-i] = tmp_key[i][j];
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    m = key.size();
    n = lock.size();
    map_size = n + 2*(m-1);
    vector<vector<int>> map(map_size, vector<int> (map_size,0));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            map[i+m-1][j+m-1] = lock[i][j];
        }
    }
    // m-1 n m-1
    for(int k = 0; k < 4; k++) {
        if(k != 0) rotate(key);
        for(int i = 0; i < m+n-1; i++) {
            for(int j = 0; j < m+n-1; j++) {
                if (match_key(i,j,map,key)) {
                    return (1);   
                }
            }
        }
    }
    return (0);
}