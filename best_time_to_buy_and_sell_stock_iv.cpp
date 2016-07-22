/**
 * Best Time to Buy and Sell Stock IV My Submissions QuestionEditorial Solution
Total Accepted: 27283 Total Submissions: 120616 Difficulty: Hard
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

solution: dp method. global[i][j]表示从0-j之间最多交易i笔的全局最大值，local[i][j]表示从0-j之间以j为交易结尾
的最多交易i的最大值。
diff = prices[j]-prices[j-1]
local[i][j] = max{local[i][j-1]+diff, global[i-1][j-1] + max{0, diff}}
global[i][j] = max{local[i][j], global[i][j-1]}
corner case：记得考虑 k >= prices.size()的情况
 */

#include <iostream>
#include <vector>
using namespace std;

namespace best_time_to_buy_and_sell_stock_iv {
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k <= 0 || prices.empty())
            return 0;
        if(k >= prices.size())
        {
            int ans = 0;
            for(int i=1; i<prices.size(); i++)
                if(prices[i]-prices[i-1] > 0)
                    ans += prices[i]-prices[i-1];
            return ans;
        }
        int n = prices.size();
        vector<vector<int> > local(k+1, vector<int>(n, 0));
        vector<vector<int> > global(k+1, vector<int>(n, 0));
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    local[i][j] = 0;
                    global[i][j] = 0;
                } else {
                    int diff = prices[j]-prices[j-1];
                    local[i][j] = maxi(local[i][j-1]+diff, global[i-1][j-1] + maxi(0, diff));
                    global[i][j] = maxi(local[i][j], global[i][j-1]);
                }
            }
        }
        return global[k][n-1];
    }
    int maxi(int a, int b) {
        return a>b? a : b;
    }
};
}
