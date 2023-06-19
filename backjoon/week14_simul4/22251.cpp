#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n,k,p,x,sol;

void alloc_digit(int led[7], int num) {
	if(num == 0) {
		led[0] = 1;
		led[1] = 1;
		led[2] = 1;
		led[3] = 1;
		led[4] = 1;
		led[5] = 1;
		led[6] = 0;
	}
	else if(num == 1) {
		led[0] = 0;
		led[1] = 1;
		led[2] = 1;
		led[3] = 0;
		led[4] = 0;
		led[5] = 0;
		led[6] = 0;
	}
	else if(num == 2) {
		led[0] = 1;
		led[1] = 1;
		led[2] = 0;
		led[3] = 1;
		led[4] = 1;
		led[5] = 0;
		led[6] = 1;
	}
	else if(num == 3) {
		led[0] = 1;
		led[1] = 1;
		led[2] = 1;
		led[3] = 1;
		led[4] = 0;
		led[5] = 0;
		led[6] = 1;
	}
	else if(num == 4) {
		led[0] = 0;
		led[1] = 1;
		led[2] = 1;
		led[3] = 0;
		led[4] = 0;
		led[5] = 1;
		led[6] = 1;
	}
	else if(num == 5) {
		led[0] = 1;
		led[1] = 0;
		led[2] = 1;
		led[3] = 1;
		led[4] = 0;
		led[5] = 1;
		led[6] = 1;
	}
	else if(num == 6) {
		led[0] = 1;
		led[1] = 0;
		led[2] = 1;
		led[3] = 1;
		led[4] = 1;
		led[5] = 1;
		led[6] = 1;
	}
	else if(num == 7) {
		led[0] = 1;
		led[1] = 1;
		led[2] = 1;
		led[3] = 0;
		led[4] = 0;
		led[5] = 0;
		led[6] = 0;
	}
	else if(num == 8) {
		led[0] = 1;
		led[1] = 1;
		led[2] = 1;
		led[3] = 1;
		led[4] = 1;
		led[5] = 1;
		led[6] = 1;
	}
	else if(num == 9) {
		led[0] = 1;
		led[1] = 1;
		led[2] = 1;
		led[3] = 1;
		led[4] = 0;
		led[5] = 1;
		led[6] = 1;
	}
}

int disp_diff_cnt(int disp_info[2][7])
{
	int cnt = 0;

	for (int i = 0; i < 7; i++)
	{
		if(disp_info[0][i] != disp_info[1][i]) {
			cnt++;
		}
	}
	return (cnt);
}

void toggle_cnt(int st, int dst)
{
	int total_cnt = 0;
	// int base_dst = dst;
	// dst와 st를 k자리수만큼 비교
	for (int i = 0; i < k; i++)
	{
		int st_digit = st % 10;
		int dst_digit = dst % 10;
		st = st / 10;
		dst = dst / 10;
		
		// 각 자리수에 대해, toggle횟수 비교과정은 다음과 같다.
		int disp_info[2][7];
		memset(disp_info, 0, sizeof(disp_info));
		// st_digit를 disp_info[0]에 할당.
		alloc_digit(disp_info[0], st_digit);
		// dst_digit를 disp_info[1]에 할당.
		alloc_digit(disp_info[1], dst_digit);
		int cnt = disp_diff_cnt(disp_info);
		// cout << st_digit << ' ' << dst_digit << ' ' << cnt << ' ';
		total_cnt += cnt;
	}
	// cout << '\n';
	if (total_cnt >= 1 && total_cnt <= p) {
		// cout << base_dst << ": " << total_cnt << "개"<< '\n'; // @test
		sol++;
	}
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> k >> p >> x;
	// k자리수의 display에 대해, 0 <= i < 10^k 까지 순회
	for (int i = 1; i < pow(10,k); i++)
	{
		if(i > n)
			break;
		// 각 display로 변경하기 위해 필요한 toggle횟수를 toggle_cnt(x, i)로 계산.
		toggle_cnt(x, i);
	}
	
	cout << sol << '\n';
}

// 9 1 2 5

// n < 1000000
// 1~n층 가능.
// k자리의 수 display.
// 7개의 표시등으로 display.
// 최대 p개 반전.
// 현재 x층.

// x층에서 바꿀수 있는 경우의 수를 출력.
