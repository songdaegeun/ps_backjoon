#include <iostream>
#include <cmath>
using namespace std;

int arr[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	string str;
	cin >> str;
	// 필요한 번호의 개수를 센다.
	// 6 or 9는 같은 걸로 취급하고 2로 나눈 후 ceil.
	// 번호의 최대값 출력.
	int num = stoi(str);
	while (num)
	{
		int digit = num % 10;
		if(digit == 9)
			digit = 6;
		arr[digit]++;
		num /= 10;
	}
	arr[6] = ceil((double)arr[6] / 2);
	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	
	cout << max;
}