#include <iostream>
#include <string>
#include <vector>
#define NUM 11
#define MAX_LEN 16
#define MEMOVER_HALT(size) if( (size) > 128) return 0
using namespace std;

vector<char> res;
int n = NUM;
string arr[101];

int get_len(string &str)
{
	int ret[5] = {1,2,4,8,16};;
	int ret_idx = -1;
	if(str == "BOOL")
		ret_idx = 0;
	else if(str == "SHORT")
		ret_idx = 1;
	else if(str == "FLOAT")
		ret_idx = 2;
	else if(str == "INT")
		ret_idx = 3;
	else if(str == "LONG")
		ret_idx = 4;
	return (ret[ret_idx]);
}

int sol(string *arr)
{
	// res에 붙히기 직전에 8보다 작다면 8이 되도록 padding 후 ',' 붙히기.
	int prev_len = 0;
	int total_len = 0;
	for (int i = 0; i < NUM; i++)
	{
		// arr[i]를 보고 개수를 리턴하는 함수.
		int cur_len = get_len(arr[i]);
		// 이전 개수보다 현재 개수가 크면 개수가 그만큼 되도록 padding.

		while(prev_len != 0 && prev_len < cur_len )
		{
			res.push_back('.');
			prev_len++;
			if(prev_len == 8)
			{
				res.push_back(',');
				total_len += prev_len;
				prev_len = 0;
				break;
			}
		}

		for (int j = 0; j < cur_len; j++)
		{
			res.push_back('#');
			prev_len++;
			if(prev_len % 8 == 0) 
			{
				res.push_back(',');
				total_len += prev_len;
				prev_len = 0;
			}
		}
		if((prev_len == 0) && (i == NUM - 1))
		{
			res.pop_back();
			prev_len = 8;
		}
		if(total_len > 128)
			return (0);
	}
	total_len += prev_len;
	if(total_len > 128)
		return (0);
	while (prev_len < 8)
	{
		res.push_back('.');
		prev_len++;
	}
	return (1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	for (int i = 0; i < n; i++)
	{
		getline(cin, arr[i], ',');
	}	
	if(!sol(arr))
		cout << "HALT";
	else
	{
		for(auto ch:res)
		{
			cout << ch ;
		}
	}
}

// INT,INT,BOOL,SHORT,LONG,
// INT,SHORT,FLOAT,INT,BOOL,
// FLOAT,SHORT,BOOL,BOOL,BOOL,INT,
// BOOL,LONG,SHORT,LONG,BOOL,LONG,BOOL,LONG,SHORT,LONG,LONG,

// BOOL,LONG,SHORT,LONG,
