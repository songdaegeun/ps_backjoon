// Two_Sum_II_Input_Array_Is_Sorted

#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> ret;
		int st = 0;
		int en = numbers.size()-1;
		while(st<en) {
			if(numbers[st]+numbers[en] < target) {
				st++;
			}
			else if(numbers[st]+numbers[en] > target) {
				en--;
			}
			else {
				ret.push_back(st+1);
				ret.push_back(en+1);
				return (ret);
			}
		}
		return (ret);
	}
};

int main() {

}

// Example 1:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
