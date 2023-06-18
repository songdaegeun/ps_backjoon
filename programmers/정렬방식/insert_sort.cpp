#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10] = {8,2,85,89,564,4,1,854,41,41};
    // 1~ n -1 동안 나보다 뒤에 있는 요소들 중 나보다 큰 것을 나한테까지 밀고 빈 자리에 나를 채움.
    for (int i = 1; i < 10; i++)
    {
        int key = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if(arr[j] > key) arr[j + 1] = arr[j];
            else break;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    
}