#include <iostream>
#include <string>
#include <vector>
#define NUM 5
#define MAX_LEN 16
using namespace std;

vector<char> res;
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

void sol(string *arr)
{
	
	// res에 붙히기 직전에 8보다 작다면 8이 되도록 padding 후 ',' 붙히기.
	int prev_len = 0;
	
	for (int i = 0; i < NUM; i++)
	{
		vector<char> tmp_res;
		// arr[i]를 보고 개수를 리턴하는 함수.
		int cur_len = get_len(arr[i]);
		// 이전 개수보다 현재 개수가 크면 개수가 그만큼 되도록 padding.
		while(prev_len != 0 && prev_len < cur_len)
		{
			tmp_res.push_back('.');
			prev_len++;
			if(prev_len == 8)
			{
				tmp_res.push_back(',');
				break;
			}
		}
		for (int j = 0; j < cur_len; j++)
		{
			tmp_res.push_back('#');
			if(j == 7)
				tmp_res.push_back(',');
		}
		for (int j = 0; j < tmp_res.size(); j++)
		{
			res.push_back(tmp_res[j]);
		}
		if(tmp_res.back() == ',')
		{
			prev_len = 0;
		}
		else
			prev_len += tmp_res.size();
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	string arr[101];
	int n = NUM;
	for (int i = 0; i < n; i++)
	{
		getline(cin, arr[i], ',');
	}
	sol(arr);
	for(auto ch:res)
	{
		cout << ch ;
	}
}

// INT,INT,BOOL,SHORT,LONG,