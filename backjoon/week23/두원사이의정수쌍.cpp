#include <iostream>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
	// x^2 + y^2 = r^2
	for (int i = 1; i < r2; i++)
	{
		int upper_b = 0;
		int lower_b = 0;
		
		upper_b = (int)floor(sqrt(pow(r2,2)-pow(i,2)));
		if(i < r1) {
			lower_b = (int)ceil(sqrt(pow(r1,2)-pow(i,2)));
		}
		else {
			lower_b = 1;
		}
		answer += upper_b - lower_b + 1;
		
	}
	answer += r2-r1+1;

	return 4*answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cout << solution(2,3) << '\n';
	// solution(2,3)
}

// 두 원 사이의 공간에 x좌표와 y좌표가 모두 정수인 점의 개수 반환.
