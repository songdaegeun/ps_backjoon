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
    string str, arr_int;
    int n, len;

    
    cin >> n;
    while(n--)
    {
        int ft_errno = 0;
        int data = 0;
        int rev_flag = 0;
        cin >> str >> len;
        cin >> arr_int;
        for(int i = 1; i < arr_int.length() && len != 0; i++)
        {
            if(arr_int[i] != ',' && arr_int[i] != ']')
                data = data * 10 + arr_int[i] - '0';
            else
            {
                deq.push_back(data);
                data = 0;
            }
        }
        for(char c: str)
        {
            if(c =='R')
            {
                rev_flag ^= 1;
            }
            else
            {
                if(!deq.empty())
                {
                    if(rev_flag)
                        deq.pop_back();
                    else
                        deq.pop_front();
                }
                else
                {
                    ft_errno = 1;
                    cout << "error" << '\n';
                    break;
                }
            }
        }
        if(!ft_errno)
        {
            if(rev_flag)
            {
                for(int i = 0; i < deq.size() / 2; i++)
                {
                    int tmp;
                    tmp = deq[i];
                    deq[i] = deq[deq.size() - 1 - i];
                    deq[deq.size() - 1 - i] = tmp;
                }
                // reverse(deq.begin(), deq.end());
            }
            cout << '[';
            while(!deq.empty())
            {
                cout << deq.front();
                deq.pop_front();
                if(!deq.empty())
                    cout << ',';
            }
            cout << "]\n";
        }
    }
}

// 4
// RDD
// 4
// [1,2,3,4]
// DD
// 1
// [42]
// RRD
// 6
// [1,1,2,3,5,8]
// D
// 0
// []