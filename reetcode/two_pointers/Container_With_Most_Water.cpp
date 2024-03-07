// Container_With_Most_Water
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int st = 0;
		int en = height.size()-1;
		int area = 0;
		while(st<en) {
			area = max(area, (en-st)*min(height[st],height[en]));
			if(height[st] <= height[en])
				st++;
			else if(height[st] > height[en])
				en--;
		}
		return (area);
	}
};

int main() {

}


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.