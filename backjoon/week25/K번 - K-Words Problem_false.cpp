#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int n;

int before_of(string str) {
	int str_size = str.size();
	if(str[str_size-1] == '!' || str[str_size-1] == ',' || str[str_size-1] == '?') { // .는 등장하지 않음 
		return (0);
	}
	else
		return (1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	cin.ignore();
	string str;
	while(n--) {
		getline(cin, str);
		vector<string> words;
		stringstream ss(str);
		string tmp;
		while (getline(ss, tmp, ' ')) {
			words.push_back(tmp);
		}

		vector<string> new_words;
		int i,mov;

		i = 0; 
		while (i < words.size()) {
			mov = 0;
			while(words[i] == "Korea" && (i==0 || i>=1 && (words[i-1] != "of")) && !(words[i+1] == "of" && words[i+2].substr(0,5) == "Korea") ) {
				i++;
				mov++;
			}
			string str_sum = words[i];
			if(i != (words.size())) {
				if(mov)
					str_sum[0] = toupper(str_sum[0]);
				while(mov--) {
					str_sum = "K-" + str_sum;
				}
			}
			else {
				str_sum = words[i-1];
			}
			// cout << i << ':' << str_sum << '\n';
			new_words.push_back(str_sum);
			i++;
		}

		vector<string> last_words;
		i = 0;
		while (i < new_words.size()) {
			mov = 0;
			string str_sum = new_words[i];
			while(i+2 < new_words.size() && before_of(new_words[i]) && new_words[i+1] == "of" && new_words[i+2].substr(0,5) == "Korea") {
				if(new_words[i+2][5] != 0)
					str_sum = str_sum + string(1, new_words[i+2][5]);
				i+=2;
				mov++;
			}
			if(mov)
				str_sum[0] = toupper(str_sum[0]);
			while(mov--) {
				str_sum = "K-" + str_sum;
			}
			last_words.push_back(str_sum);
			i++;
		}

		for (int i = 0; i < last_words.size(); i++)
		{
			if(i!=(last_words.size()-1))
				cout << last_words[i] << ' ';
			else
				cout << last_words[i] << '\n';
		}
		// cout << '\n';
	}
}

// 1
// Korea is our country.



// 문장부호: 느낌표(!), 물음표(?), 쉼표(,), 마침표(.)

// 보고서에 단어 'Korea'가 등장할 경우, 다음에 나오는 단어와 합쳐 'K-단어'로 축약한다. (ex. Korea language → K-Language)
// 단어 'Korea'는 대문자와 소문자를 구분한다.
// 단어 'Korea' 다음에 나오는 단어의 첫 글자가 소문자일 경우 대문자로 변환한다.
// 이 규칙을 여러 번 연달아 적용할 수 있는 경우 뒤에서부터 적용한다.
// 단어 'Korea' 뒤에 문장 부호가 붙어 있는 경우 이 규칙을 적용할 수 없다.

// 보고서에 단어 'of' 직후에 단어 'Korea'가 등장할 경우, 단어 'of' 직전에 나오는 단어와 합쳐 K-단어로 축약한다. (ex. Language of Korea → K-Language)
// 단어 'of'와 'Korea'는 대문자와 소문자를 구분한다.
// 단어 'of' 직전에 나오는 단어의 첫 글자가 소문자일 경우 대문자로 변환한다.
// 이 규칙을 여러 번 연달아 적용할 수 있는 경우 앞에서부터 적용한다.
// 단어 'of' 뒤에 문장 부호가 붙어 있는 경우 이 규칙을 적용할 수 없다.
// 단어 'of' 앞에 단어가 없거나, 단어 'of' 직전에 나오는 단어에 문장 부호가 붙어 있는 경우 이 규칙을 적용할 수 없다. // @
// 단어 'Korea' 뒤에 문장 부호가 붙어있는 경우, 단어 'Korea' 뒤의 문장 부호를 단어 'of' 직전에 나오는 단어 뒤에 붙인다. 

// 1번 규칙과 2번 규칙을 한 문장에 동시에 적용할 수 있는 경우, 2번 규칙을 먼저 적용한다.

// 7
// Artichoke in Korea Army uses Aheui.
// Aheui, the best language of Korea.
// Korea is our country.
// of Korea? Korea Korea Aheui of Korea.
// Language of, Korea Korea.
// Aheui has shown the greatness of Korea of Korea.
// korea Korea! koRea Of Korea of Korea oF kORea.