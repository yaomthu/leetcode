/**
 * Max Sum of Rectangle No Larger Than K
 * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?

Solution: This question can be solved based on a sub problem: get the maximum subarray no more than k,
 whose time complexity is O(mlogm). Loop all set of (col_left, col_right) and use the sub problem's
 algorithm.
 Time complexity: O(min{m,n}^2 * max{m,n}log(max{m,n}))
 space complexity: O(max{m,n})
 *
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

namespace max_sum_of_rectangle_no_larger_than_k {
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int> >& matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        vector<int> dp(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j == i) {
                    for (int p = 0; p < m; p++)
                        dp[p] = matrix[p][i];
                } else {
                    for (int p = 0; p < m; p++)
                        dp[p] += matrix[p][j];
                }
                int maximum = getMaxSubarray(dp, k);
                cout << i << " " << j << " " << maximum << endl;
                if (maximum > ans)
                    ans = maximum;
            }
        }
        return ans;
    }
    int getMaxSubarray(vector<int>& nums, int k) {
        set<int> record;
        int sum = 0;
        int ans = INT_MIN;
        for (auto num : nums) {
            sum += num;
            auto iter = record.lower_bound(sum - k);
            if (iter != record.end() && sum - *iter > ans)
                ans = sum - *iter;
            if (sum <= k && sum > ans)
                ans = sum;
            record.insert(sum);
        }
        return ans;
    }
};
}

int main_max_sum_of_rectangle_no_larger_than_k() {
  int data[2][3] = {{1,0,1},{0,-2,3}};
  vector<vector<int> > matrix;
  for (int i = 0; i < 2; i++)
    matrix.push_back(vector<int>(data[i], data[i]+3));
  cout << (new max_sum_of_rectangle_no_larger_than_k::Solution())->maxSumSubmatrix(matrix, 2);
}
