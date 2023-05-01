
#include <iostream>
// #define METHOD1
#define METHOD2
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10] = {8,2,85,89,564,4,1,854,41,41};
    #ifdef METHOD1
    // 큰 걸 뒤로 보내는 방법
    for (int i = 9; i > 0; i--)
    {
        int maxidx = 0;
        for (int j = 1; j <= i; j++)
        {
            if(arr[maxidx] < arr[j]) maxidx = j;
        }
        int tmp = arr[maxidx];
        arr[maxidx] = arr[i];
        arr[i] = tmp;
    }
    #endif
    #ifdef METHOD2
    // 작은 걸 앞으로 보내는 방법
    for(int i = 0; i < 10; i++)
    {
        int minidx = i;
        for (int j = i + 1; j < 10; j++)
        {
            if(arr[minidx] > arr[j])
            {
                minidx = j;
            }
        }
        int tmp = arr[minidx];
        arr[minidx] = arr[i];
        arr[i] = tmp;
    }


    #endif
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}