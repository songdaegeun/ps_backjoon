class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int en = nums.size()-1;
        int ret = INT_MAX;

        while(st <= en) {
            int mid = (st + en)/2;
            ret = min(ret, nums[mid]);
            if(nums[mid] < nums[en]) {
                en = mid-1;
            }
            else {
                st = mid+1;
            }
        }
        return (ret);
    }
};