#include <iostream>
#include <cstring>
using namespace std;

// BOOL, SHORT, FLOAT, INT, LONG
// 1 2 4 8 16

/*
8byte단위로 구분
unit_num = 0;
unit_len = 0;

unit_len와 현재 타입의 합이 8이하인 경우
:unit_len이 현재타입보다 작다면 현재타입까지 unit_len++;
:현재타입만큼 #

unit_len와 현재 타입의 합이 8보다 큰 경우 
:unit_num++;
:현재타입만큼 #

unit_len =  (unit_len + 현재 타입)
if(unit_len > 8) {
	unit_num++;
	unit_len %= 8;
}
*/

char arr[16][8];
int unit_num, unit_len, type_len;

void disp_arr()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << arr[i][j];
		}
		cout << ",";
	}
	cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
	memset(arr, '.', sizeof(arr));
	for (int i = 0; i < n; i++)
	{
		string type_str;
		cin >> type_str;
		if(type_str == "BOOL") {
			type_len = 1;
			arr[unit_num][unit_len] = '#';
			unit_len += 1;
			if(unit_len == 8) {
				unit_num++;
				unit_len = 0;
			}
		}
		else if(type_str == "SHORT") {
			type_len = 2;
		}
		else if(type_str == "FLOAT") {
			type_len = 4;
		}
		else if(type_str == "INT") {
			type_len = 8;
		}
		else if(type_str == "LONG") {
			type_len = 16;
		}
		else {
			cout << "format error\n";
			exit(1);
		}
		if(type_len == 1) continue;
		int carry_flag = 0;
		// cout << unit_len << ',' << type_len <<  ' ';
		if((unit_len + type_len) <= 8) {
			// padding
			if(unit_len && (unit_len < type_len)) {
				unit_len = type_len;
			}
			// carry
			if((unit_len + type_len) == 8) {
				carry_flag = 1;
			}
		}
		else {
			// padding
			unit_num++;
			unit_len = 0;
		}
		unit_len %= 8;
		// 128byte를 초과하면 
		if(unit_num >= 16) {
			cout << "HALT\n";
			return (1);
		}
		// insert
		int j;
		for (j = unit_len; j < unit_len + type_len; j++)
		{
			if(j == 8)
				unit_num++;
			if(unit_num >= 16) {
				cout << "HALT\n";
				return (1);
			}
			arr[unit_num][j % 8] = '#';
		}
		if(j == 16)
			unit_num++;
		if(unit_num >= 16) {
			cout << "HALT\n";
			return (1);
		}
		unit_len = j % 8;
		if(carry_flag) {
			unit_num++;
		}
		// disp_arr();
	}
	if(arr[unit_num][0] == '.')
		unit_num--;
	cout << "\"";
	for (int i = 0; i <= unit_num; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << arr[i][j];
		}
		if(i != unit_num)
			cout << ",";
	}
	cout << "\"";
}

// BOOL, SHORT, FLOAT, INT, LONG

// 5
// INT INT BOOL SHORT LONG
// 5
// INT SHORT FLOAT INT BOOL
// 6
// FLOAT SHORT BOOL BOOL BOOL INT
// 11
// BOOL LONG SHORT LONG BOOL LONG BOOL LONG SHORT LONG LONG
// 4
// BOOL LONG SHORT LONG 