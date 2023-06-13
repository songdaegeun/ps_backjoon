#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
	string str1, str2;
	for (int i = 0; i < n; i++)
	{
		int alpha_check[26];
		memset(alpha_check, 0, sizeof(alpha_check));
		cin >> str1 >> str2;
		// str1, str2가 stringify한지 확인한다.
		// str1과 str2의 알파벳구성이 같으면 된다.
		// str1과 str2각각을 순회하며 알파벳을 arr1과 arr2에 기록한다.
		for (int i = 0; i < str1.size(); i++)
		{
			alpha_check[str1[i] - 'a']++;
		}
		for (int i = 0; i < str2.size(); i++)
		{
			alpha_check[str2[i] - 'a']--;
		}
		int flag = 0;
		for (int i = 0; i < 26; i++)
		{
			if(alpha_check[i] != 0) {
				flag = 1;
				break;
			}		
		}
		if(flag == 0)	
			cout << "Possible" << '\n';
		else
			cout << "Impossible" << '\n';
	}
	
}