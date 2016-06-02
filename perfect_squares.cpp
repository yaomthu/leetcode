/**
 * Perfect squares
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

solution: dp[i] = min(dp[i-j*j]+1)
time complexity: O(n*sqrt(n))
space complexity: O(n)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace perfect_squares{
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j*j<=i; j++) {
                if (dp[i-j*j]+1 < dp[i])
                    dp[i] = dp[i-j*j]+1;
            }
        }
        return dp[n];
    }
};
}

int main_perfect_squares() {
  cout << (new perfect_squares::Solution())->numSquares(13) << endl;
}
