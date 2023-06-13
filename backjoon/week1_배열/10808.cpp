#include <iostream>
using namespace std;

int arr[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	string str;
	cin >> str;
	for(auto el:str)
	{
		arr[el - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}