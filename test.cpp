#include <iostream>
#include <deque>
using namespace std;

// L,N <= 5,000,000 -> log(N)
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> len_deq;
    deque<int>::iterator it;

    len_deq.push_front(1);
    it = len_deq.begin();
    len_deq.push_front(2);
    len_deq.push_front(3);
    cout << *it;
    
}

// 12 3
// 1 5 2 3 6 2 3 7 3 5 2 6