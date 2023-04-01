#include <iostream>
#include <deque>
#include <stack>
using namespace std;
int chk_distance(deque<int> deq, deque<int> arr_select);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<int> deq;
    deque<int> arr_select;
    int n, size, data, cnt, dist, res;

    res = 0;
    cin >> size >> n;
    for(int i = 1; i <= size; i++)
        deq.push_back(i);
    while(n--)
    {
        cin >> data;
        arr_select.push_back(data);
    }
    while(!arr_select.empty())
    {
        int i = 0;
        dist = chk_distance(deq, arr_select);
        if(dist)
        {
            if(dist <= deq.size()/2)
            {
                //right
                while(i < dist)
                {
                    deq.push_back(deq.front());
                    deq.pop_front();
                    i++;
                }
                // cout << '[' << dist << ']' << arr_select.front() << "\n";
                res += i;
            }
            else
            {
                //left
                while(i < deq.size() - dist)
                {
                    deq.push_front(deq.back());
                    deq.pop_back();
                    i++;
                }
                // cout << '[' << dist << ']' << arr_select.front() << "\n";
                res += i;
            }
        }
        deq.pop_front();
        arr_select.pop_front();
    }
    cout << res;
}

int chk_distance(deque<int> deq, deque<int> arr_select)
{
    int cnt = 0;

    while(!deq.empty() && deq.front() != arr_select.front())
    {
        cnt++;
        deq.pop_front();
    }
    return (cnt);
}
// 10 3
// 1 2 3