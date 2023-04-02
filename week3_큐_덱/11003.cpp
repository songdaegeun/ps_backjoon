#include <iostream>
#include <deque>
using namespace std;

// L,N <= 5,000,000 -> log(N)
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque< pair<int,int> > len_deq;
    int n, len, num;

    cin >> n >> len;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        while (!len_deq.empty() && len_deq.back().second >= num)
            len_deq.pop_back();
        len_deq.push_back(make_pair(i, num));
        if(len_deq.front().first <= i - len)
            len_deq.pop_front();
        cout << len_deq.front().second << ' ';
    }
    
}

// 12 3
// 1 5 2 3 6 2 3 7 3 5 2 6