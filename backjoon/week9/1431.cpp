#include <iostream>
#include <vector>
using namespace std;

vector<char> arr[51];
int n;

int rule(vector<char> a, vector<char> b) {
    if(a.size() != b.size()) {
        return (a.size() < b.size());
    } else{
        int sum_a = 0;
        int sum_b = 0;
        for(auto ch: a) {
            if(ch >= '0' && ch <= '9')
                sum_a += ch - '0';
        }
        for(auto ch: b) {
            if(ch >= '0' && ch <= '9')
                sum_b += ch - '0';
        }
        if(sum_a != sum_b)
            return (sum_a < sum_b);
    } 
    // 사전순비교
    int i = 0;
    while(i < a.size() && i < b.size()) {
        if(a[i] != b[i]) {
            return (a[i] < b[i]);
        }
        i++;
    }
    return (0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        for (int j = 0; str[j]; j++) {
            arr[i].push_back(str[j]);
        }
    }
    sort(arr, arr + n, rule);
    for (int i = 0; i < n; i++) {
        for(auto ch : arr[i]) {
            cout << ch;
        }
        cout << '\n';
    }
}

// 5
// ABCD
// 145C
// A
// A910
// Z321