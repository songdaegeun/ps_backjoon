#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // unordered set은 hash table,
    // set은 이진검색트리 사용.
    set<string, greater<string>> set;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string person, state;
        cin >> person >> state;
        if(state == "enter") {
            set.insert(person);
        }
        else {
            if(set.find(person) != set.end())
                set.erase(person);
        }
    }
    for(auto str:set) {
        cout << str << '\n';
    }

}

// 4
// Baha enter
// Askar enter
// Baha leave
// Artem enter