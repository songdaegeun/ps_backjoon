#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	string date;
	string term_str;
	int term;

	cin >> date;
	cin >> term_str;
	term = stoi(term_str);

	// split date
	stringstream ss(date);
	vector<int> date_vec;
    string tmp;
    while (getline(ss, tmp, '-')) {
        date_vec.push_back(stoi(tmp));
    }
	long long date_int;
	
	date_int = (date_vec[0]-1) *360 + (date_vec[1]-1)*30 + (date_vec[2]-1);
	date_int += term;
	// cout << date_vec[0] <<  date_vec[1] <<  date_vec[2] << '\n';
	vector<string> answer;
	// year
	tmp = to_string(date_int/360 + 1);
	answer.push_back(tmp);
	date_int %= 360;
	// month
	tmp = to_string(date_int/30+ 1);
	// }
	if(tmp.size() < 2)
		tmp = "0" + tmp;
	answer.push_back(tmp);
	date_int %= 30;
	// day
	tmp = to_string(date_int+ 1);
	if(tmp.size() < 2)
		tmp = "0" + tmp;
	answer.push_back(tmp);

	cout << answer[0] << '-' <<  answer[1] << '-' << answer[2] << '\n';

}

// 2023-07-08
// 30

// 2023-07-08
// 22

// 2023-07-08
// 172
