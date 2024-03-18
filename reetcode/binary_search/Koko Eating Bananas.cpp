

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int en = *max_element(piles.begin(), piles.end());
        int ret = en;
        int st = 1; 
        
        while(st <= en) {
            int mid = (st+en)/2;
            // sum: 소요시간, h: 허용시간
            long int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += ceil((double)piles[i]/mid);
            }
            if(sum <= h) {
                ret = min(ret,mid);
                en = mid-1;
            }
            else {
                st = mid+1;
            }
        }
        return (ret);
    }
};