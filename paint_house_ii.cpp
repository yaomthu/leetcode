/**
 * paint house ii
 * There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?

Show Company Tags
Show Tags
Show Similar Problems
 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace paint_house_ii {
class Solution {
public:
    int minCostII(vector<vector<int> >& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;
        int n = costs.size(), k = costs[0].size();
        vector<vector<int> > dp(2, vector<int>(k, 0));
        for (int j = 0; j < k; j++)
            dp[0][j] = costs[0][j];
        int first, second;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                for (int j = 0; j < k; j++) {
                    if (first == dp[0][j])
                        dp[1][j] = second + costs[i][j];
                    else
                        dp[1][j] = first + costs[i][j];
                    dp[0][j] = dp[1][j];
                }
            }
            first = INT_MAX;
            second = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (dp[0][j] < first) {
                    second = first;
                    first = dp[0][j];
                } else if (dp[0][j] < second)
                    second = dp[0][j];
            }
        }
        return first;
    }
};
}
