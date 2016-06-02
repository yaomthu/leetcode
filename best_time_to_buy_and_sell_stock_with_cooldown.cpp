/**
 * Best Time to Buy and Sell Stock with Cooldown
 * Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

solution :
solution 1:
diff = prices[i]-prices[i-1]
local[i] = max{diff, local[i-1]+diff, global[i-3]+diff}
time complexity : O(n)
space complexity: O(n), however, the space complexity can be reduced to O(1)


solution 2:
buy[i] 表示 0-i期间以购买为结尾(不一定是第i天购买，可以是第j(<i)天购买，然后一直不再有活动)。
sell[i] 表示 0-i 期间以出售为结尾（不一定是第i天出售，可以是第j(j<i)天出售，然后一直不再有活动）
buy[i] = max{buy[i-1], sell[i-2]-prices[i]}
sell[i] = max{sell[i-1], buy[i-1]+prices[i]}
注意，buy[0] = -prices[0], sell[0] = 0, sell[-1] = 0
time complexity : O(n)
space complexity: O(n), however, the space complexity can be reduced to O(1)

 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace best_time_to_buy_and_sell_stock_with_cooldown {
class Solution_1 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int n = prices.size();
        vector<int> local(n, 0);
        vector<int> global(n, 0);
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i]-prices[i-1];
            local[i] = diff;
            if (local[i] < local[i-1] + diff)
                local[i] = local[i-1] + diff;
            if (i > 2) {
                if (local[i] < global[i-3]+diff)
                    local[i] = global[i-3] + diff;
            }
            global[i] = global[i-1] > local[i]? global[i-1] : local[i];
        }
        return global[n-1];
    }
};

class Solution_2 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int n = prices.size();
        vector<int> sell(n, 0);
        vector<int> buy(n, 0);
        buy[0] = -prices[0];
        for (int i=1; i<prices.size(); i++) {
            if (i >= 2)
                buy[i] = buy[i-1]>sell[i-2]-prices[i]? buy[i-1] : sell[i-2]-prices[i];
            else
                buy[i] = buy[i-1]>-prices[i]? buy[i-1] : -prices[i];
            sell[i] = sell[i-1]>buy[i-1]+prices[i]? sell[i-1] : buy[i-1]+prices[i];
        }
        return sell[n-1];
    }
};
}

int main_best_time_to_buy_and_sell_stock_with_cooldown() {
  int data[] = {2,1,4};
  vector<int> prices(data, data+3);
  cout << (new best_time_to_buy_and_sell_stock_with_cooldown::Solution_1())->maxProfit(prices);
}
