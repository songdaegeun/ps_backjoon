#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class mem
{
public:
	int age;
	string name;
};

int user_sort(mem a, mem b)
{
	if(a.age != b.age) return (a.age < b.age);
	else
		return (0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<mem> v;
	int n;
	cin >> n;
	while(n--)
	{
		mem member;
		cin >> member.age;
		cin.ignore();
		getline(cin, member.name);
		v.push_back(member);	
	}

	stable_sort(v.begin(), v.end(), user_sort);
	for (auto el:v)
	{
		cout << el.age << ' ' << el.name << '\n';
	}
}

// 3
// 21 Junkyu
// 21 Dohyun
// 20 Sunyoung