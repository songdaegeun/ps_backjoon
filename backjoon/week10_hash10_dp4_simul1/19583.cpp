#include <iostream>
#include <unordered_set>
using namespace std;

int ttoi(string s_time) {
	int i_time;
	int hour = (s_time[0] - '0') * 10 + (s_time[1] - '0');
	int min = (s_time[3] - '0') * 10 + (s_time[4] - '0');
	i_time = hour * 60 + min;
	return i_time;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	string s,e,q;
	cin >> s >> e >> q;
	int i_s, i_e, i_q;
	i_s = ttoi(s);
	i_e = ttoi(e);
	i_q = ttoi(q);
	string time, nickname;
	unordered_set<string> chk_in;
	unordered_set<string> chk_out;
	int ans = 0;
	do
	{
		cin >> time >> nickname;
		if(cin.eof()) break;	
		// 백준에서 입력 종료조건이 없을 때는 eof가 들어올 때 종료하면 된다.
		// ./program < input0x.txt > output0x.txt 로 입력이 들어오기때문.
		int i_time = ttoi(time);
		if(i_time <= i_s)
		{
			chk_in.insert(nickname);
		}
		else if(i_e <= i_time && i_time <= i_q) {
			if(chk_in.find(nickname) != chk_in.end()) {
				chk_in.erase(nickname);
				ans++;
			}
		}

	} while (1); // 시간 비교 함수 짜야 함.
	cout << ans << '\n';
	
}

// 22:00 23:00 23:30
// 21:30 malkoring
// 21:33 tolelom
// 21:34 minjae705
// 21:35 hhan14
// 21:36 dicohy27
// 21:40 906bc
// 23:00 906bc
// 23:01 tolelom
// 23:10 minjae705
// 23:11 hhan14
// 23:20 dicohy27