#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
        unordered_map<string, int> cloth;
        int n;
        cin >> n;
        while(n--) {
            string str1, str2;
            cin >> str1 >> str2;
            if (cloth.find(str2) != cloth.end())
                cloth[str2]++;
            else
                cloth[str2] = 1;
        }
        int ans = 1;
        for(auto el:cloth) {
           ans *= (el.second + 1);
        }
        cout << ans - 1 << '\n';
    }
   
}

// 2
// 3    
// hat headgear
// sunglasses eyewear
// turban headgear
// 3
// mask face
// sunglasses face
// makeup face


// face: 3 -> 총 1종류
// 1종류선택: 3C1 = 3

// 종류가 중복되면 안됨.