/**
 * Coin Change
 * You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Solution: dp[i] 表示组合成价值i的最少硬币数，每个元素初始化为INT_MAX, 考虑每个硬币时，把数组dp更新一遍。
注意讨论amount = 0 和 coin值比amount大的时候就不考了该coin了。
time complexity: O(n*amoount)
space complexity: O(amount)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace coin_change {
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty() || amount < 0)
            return -1;
        if (amount == 0)
            return 0;
        vector<int> dp(amount+1, INT_MAX);
        for (int i=0; i<coins.size(); i++) {
            if (coins[i] > amount)
                continue;
            dp[coins[i]] = 1;
            for (int j=coins[i]+1; j<=amount; j++) {
                if (dp[j-coins[i]] != INT_MAX && dp[j-coins[i]]+1 < dp[j])
                    dp[j] = dp[j-coins[i]]+1;
            }
        }
        return dp[amount]==INT_MAX? -1 : dp[amount];
    }
};
}

int main_coin_change() {
  int data[] = {1,2,5};
  vector<int> coins(data, data+3);
  cout << (new coin_change::Solution())->coinChange(coins, 11);
}
