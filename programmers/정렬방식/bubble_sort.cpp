#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10] = {8,2,85,89,564,4,1,854,41,41};
    
    for (int i = 0; i < 10 - 1; i++)
    {
        // 앞에서부터 2개씩 비교하면서 큰 것들을 뒤로 보낸다.
        // i를 통해 어디서부터 비교할지 선택한다.
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    
}