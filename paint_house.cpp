/**
 * Paint house
 *
 * There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Show Company Tags
Show Tags
Show Similar Problems
 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace paint_house {
class Solution {
public:
    int minCost(vector<vector<int> >& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;
        int n = costs.size();
        vector<vector<int> > dp(2, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                for (int j = 0; j < 3; j++)
                    dp[1][j] = costs[i][j];
            } else {
                for (int j = 0; j < 3; j++)
                    dp[1][j] = mins(dp[0][(j+1)%3], dp[0][(j+2)%3]) + costs[i][j];
            }
            for (int j = 0; j < 3; j++)
                dp[0][j] = dp[1][j];
        }
        int ans = INT_MAX;
        for (int j = 0; j < 3; j++)
            if (dp[1][j] < ans)
                ans = dp[1][j];
        return ans;
    }

    int mins(int a, int b) {
        return a < b? a : b;
    }
};
}

