#include <iostream>
#include <string.h>
#include <stdbool.h>
#include <algorithm>

using namespace std;

string fivo[500];

string str_sum(string a, string b) {
	string ret = "";
	int carry = 0;
	int i = a.length() - 1;
	int j = b.length() - 1;
	while (i >= 0 || j >= 0) {
		int sum = carry;
		if (i >= 0) sum += a[i] - '0';
		if (j >= 0) sum += b[j] - '0';
		ret += to_string(sum % 10);
		carry = sum / 10;
		i--; j--;
	}
	if (carry != 0) ret += to_string(carry);
	reverse(ret.begin(), ret.end());
	return ret;
}

bool std_greater(string a, string b) {
	if (a.length() < b.length()) return true;
	else if (a.length() > b.length()) return false;
	else {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] < b[i]) return true;
			else if (a[i] > b[i]) return false;
		}
	}
	return false;
}

long long make_fivo(string a, string b) {
	fivo[0] = "0";
	fivo[1] = "1";
	int i = 2;
	while (1){
		fivo[i] = str_sum(fivo[i-1], fivo[i-2]);		
		if(std_greater(b, fivo[i])) {
			break;
		}
		i++;
	}
	int st = 2;
	while(std_greater(fivo[st], a)) {
		st++;
	}
	return (i - st);
}
// 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	string a, b;
	while (cin >> a >> b) {
		fill(fivo, fivo + 500, "");
		if (a == "0" && b == "0") break;
		cout << make_fivo(a, b) << '\n';	
	}
	return 0;
}

// 10 100
// 1234567890 9876543210
// 0 0

// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610