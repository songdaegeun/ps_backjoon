// Largest_Rectangle_in_Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = -1;
        stack<pair<int,int>> stk;
        int area;
        // stack에 단조오름차순으로 담음
        for(int i = 0; i < heights.size(); i++) {
            int save_idx = i;
            while(!stk.empty() && heights[i] < stk.top().first) {
                save_idx = stk.top().second;
                area = (i - save_idx) * stk.top().first;
                if(area > ans)
                    ans = area;
                stk.pop();
            }
            stk.push({heights[i], save_idx});            
        }
        while(!stk.empty()) {
            area = (heights.size() - stk.top().second) * stk.top().first;
            if(area > ans)
                ans = area;
            stk.pop();
        }
        return (ans);
    }
};