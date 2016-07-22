/**
 * Maximum square
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

solution: dp method. dp[i][j] 表示以位置(i,j)为右下角的最大矩形的长度。
dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
 */

#include <iostream>
#include <vector>
using namespace std;

namespace maximum_square {
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for (int j=0; j < n; j++) {
                if (i == 0)
                    dp[i][j] = matrix[i][j]=='1'? 1 : 0;
                else if (j == 0)
                    dp[i][j] = matrix[i][j]=='1'? 1: 0;
                else {
                    if (matrix[i][j] == '0')
                        dp[i][j] = 0;
                    else
                        dp[i][j] = 1 + minThree(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]);
                }
                if (dp[i][j] > ans)
                    ans = dp[i][j];
            }
        }
        return ans*ans;
    }
    int minThree(int a, int b, int c) {
        int ans = INT_MAX;
        if (a < ans)
            ans = a;
        if (b < ans)
            ans = b;
        if (c < ans)
            ans = c;
        return ans;
    }
};
}
