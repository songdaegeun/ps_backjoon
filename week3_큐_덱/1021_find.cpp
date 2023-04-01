#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int chk_distance(deque<int> deq, deque<int> arr_select);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<int> deq;
    deque<int> arr_select;
    int n, size, target_idx, res;

    res = 0;
    cin >> size >> n;
    for(int i = 1; i <= size; i++)
        deq.push_back(i);
    while(n--)
    {
        cin >> target_idx;
        int idx = find(deq.begin(), deq.end(), target_idx) - deq.begin();
        if(idx)
        {
            while(deq.front() != target_idx)
            {
                if(idx <= deq.size()/2)
                {
                    deq.push_back(deq.front());
                    deq.pop_front();
                }
                else
                {
                    deq.push_front(deq.back());
                    deq.pop_back();
                }
                res++;
            }
        }
        deq.pop_front();
    }
    cout << res;
}


// 10 3
// 1 2 3