#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, el, i, j, k;
    int arr[500001];
    long long sum;
    cin >> n;
    sum = 0;
    i = 0;
    while(i < n)
    {
        cin >> el;
        arr[i] = el;
        i++;
    }
    i = 0;
    while(i < n - 1)
    {
        j = i + 1;
        while(j < n)
        {
            if(j - i > 1)
            {
                k = i + 1;
                while(arr[i] >= arr[k] && arr[k] <= arr[j] && k < j)
                    k++;
                if (k == j)
                    sum++;
            }
            else
            {
                sum++;
            }
            j++;
        }
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