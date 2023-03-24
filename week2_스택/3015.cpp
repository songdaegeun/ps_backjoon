#include <iostream>
#include <stack>
using namespace std;

void solve(int n);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    solve(n);
}

void solve(int n)
{
    int el, i, num;
    int arr[500001];
    long long sum;
    stack< pair<int, int> > s;

    i = 0;
    while(i < n)
    {
        cin >> el;
        arr[i] = el;
        i++;
    }
    i = 0;
    while(i < n)
    {
        num = 1;
        while(s.size() && s.top().first <= arr[i])
        {
            if(s.top().first == arr[i])
            {
                num = s.top().second + 1;
                sum += s.top().second;
                s.pop();
            }
            else
            {
                sum += s.top().second;
                s.pop();
                num = 1;
            }
        }
        if(s.size())
           sum++;
        s.push({arr[i], num}); //-std=c++11
        // s.push(make_pair(arr[i], num));
        i++;
    }
    cout << sum;
}

// // 입력 1
// 5
// 5 5 2 2 5

// // 출력 1
// 8



// // 입력 2
// 5
// 5 5 2 1 5

// // 출력 2
// 7



// // 입력 3
// 5
// 5 3 1 3 7

// // 출력 3
// 8



// // 입력 4
// 5
// 3 2 2 1 2

// // 출력 4
// 8



// // 입력 5
// 5
// 4 1 2 2 5

// // 출력 5
// 8



// // 입력 6
// 5
// 4 1 2 3 5

// // 출력 6
// 7



// // 입력 7
// 5
// 4 1 2 3 5

// // 출력 7
// 7



// // 입력 8
// 5
// 4 1 2 2 1

// // 출력 8
// 6



// // 입력 9
// 5
// 4 1 2 3 1

// // 출력 9
// 6



// // 입력 10
// 4
// 7 7 7 7

// // 출력 10
// 6



// // 입력 11
// 6
// 6 6 6 5 2 5

// // 출력 11
// 8



// // 입력 12
// 4
// 4 3 1 2

// // 출력 12
// 4



// // 입력 13
// 2
// 3 3

// // 출력 13
// 1



// // 입력 14
// 4
// 4 4 1 2

// // 출력 14
// 4



// // 입력 15
// 3
// 3 2 1

// // 출력 15
// 2



// // 입력 16
// 4
// 1 2 2 1

// // 출력 16
// 3



// // 입력 17
// 5
// 1 2 2 2 1

// // 출력 17
// 5



// // 입력 18
// 3
// 5 5 2

// // 출력 18
// 2



// // 입력 19
// 5
// 5 3 1 3 7

// // 출력 19
// 8