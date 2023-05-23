#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> nums({3,3,3,2,2,2});

int n;
int max_ans = -1;
unordered_map<int,int> choice;

void combi(int depth, vector<int> &nums, int st)
{
    if(depth == n / 2)
    {
        int tmp = 0;
        for(auto el:choice) {
            if(el.second != 0)
                tmp++;
        }
        if(max_ans < tmp)
            max_ans = tmp;
        return ;
    }    
    for(int i = st; i < n; i++) {
        choice[nums[i]]++;
        combi(depth + 1, nums, i + 1);
        choice[nums[i]]--;
    }
    
}

int solution(vector<int> &nums)
{
    n = nums.size();
    
    combi(0, nums, 0);
    return max_ans;
}

int main() {

	cout << solution(nums);
	return (0);
}