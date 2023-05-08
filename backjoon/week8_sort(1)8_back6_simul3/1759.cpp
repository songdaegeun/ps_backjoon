#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char ch_set[16];
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
int vowel_cnt;
int not_vowel_cnt;

vector<char> v;
int l, c;

int is_vowel(char ch)
{
	for (int i = 0; i < 5; i++)
	{
		if(vowel[i] == ch)
			return (1);
	}
	return (0);
}

void choice(int st_i, int depth)
{
	if(depth == l)
	{
		if(vowel_cnt >= 1 && not_vowel_cnt >= 2)
		{
			for(auto ch:v)
				cout << ch;
			cout << '\n';
		}
		return ;
	}
	for (int i = st_i; i < c; i++)
	{
		if(is_vowel(ch_set[i]))
		{
			vowel_cnt++;
			v.push_back(ch_set[i]);
			choice(i + 1, depth + 1);
			v.pop_back();
			vowel_cnt--;
		}
		else
		{
			not_vowel_cnt++;
			v.push_back(ch_set[i]);
			choice(i + 1, depth + 1);
			v.pop_back();
			not_vowel_cnt--;
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> ch_set[i];
	sort(ch_set, ch_set + c);
	
	choice(0, 0);
}

// 4 6
// a t c i s w