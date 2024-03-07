// Trapping_Rain_Water
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		int st = 0;
		int en = height.size()-1;
		int prev = 0;
		int area = 0;
		while(st < en) {
			while(st<en && height[st] <= height[en]) {
				prev = max(prev, height[st]);
				area += prev - height[st];
				st++;
			}
			while(st<en && height[st] > height[en]) {
				prev = max(prev,height[en]);
				area += prev - height[en];
				en--;
			}
		}
		return (area);
	}
};

int main() {

}
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
