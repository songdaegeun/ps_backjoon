#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
// string arr[20001];
vector<string> arr;

int compare(string a, string b) {
    if(a.length() != b.length()) { 
        return (a.length() < b.length());
    }
    else {
        return (a < b);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        arr.push_back(str);
        // cin >> arr[i];
    }
    // 길이가 짧은 것부터
    // 길이가 같으면 사전 순으로
    // sort(arr, arr + n, compare);
    sort(arr.begin(), arr.end(), compare);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    
    for(auto str:arr)
    {
        cout << str << '\n';
    }
    // string prev = "";
    // for (int i = 0; i < n; i++)
    // {
    //     if(prev != arr[i]) {
    //         cout << arr[i] << '\n';
    //     }
    //     prev = arr[i];
    // }
}

// 13
// but
// i
// wont
// hesitate
// no
// more
// no
// more
// it
// cannot
// wait
// im
// yours