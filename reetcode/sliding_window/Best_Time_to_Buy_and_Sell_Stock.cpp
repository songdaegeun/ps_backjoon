// Best_Time_to_Buy_and_Sell_Stock

#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int st = 0;
		int en =0;
		int ans = 0;
		while(en<prices.size()) {
			if(prices[en] > prices[st]) {
				ans = max(ans, prices[en] - prices[st]);
			}
			else {
				st = en;
			}
			en++;
		}
		return (ans);
	}
}
 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.