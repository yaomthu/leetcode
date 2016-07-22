/**
 * Maximum sum rectangular
 * find the max sum rectangle in 2D array
 *
 * solution: Loop every set of (up_row, bottom_row), calculate the maximum subarray.
 * time complexity: O(m^2*n)
 * space complexity: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace maximum_sum_rectangular {
class Solution {
 public:
  int getMaximumSumRectangular(vector<vector<int> >& matrix) {
    if (matrix.empty() || matrix[0].empty())
      return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = INT_MIN;
    vector<int> dp(n, 0);
    for (int i = 0; i < m; i++) {
      for (int j = i; j < m; j++) {
        if (j == i) {
          for (int k = 0; k < n; k++)
            dp[k] = matrix[i][k];
        } else {
          for (int k = 0; k < n; k++)
            dp[k] += matrix[j][k];
        }
        int maximum = getMaxSubarray(dp);
        if (maximum > ans)
            ans = maximum;
      }
    }
    return ans;
  }

  int getMaxSubarray(vector<int>& nums) {
    if (nums.empty())
      return 0;
    int sum = 0;
    int ans = INT_MIN;
    for (auto num : nums) {
      sum += num;
      if (sum > ans)
        ans = sum;
      if (sum < 0)
          sum = 0;
    }
    return ans;
  }
};
}

int main_maximum_sum_rectangular() {
  int data[4][4] = {{-1,2,4,-3},
                    {3,2,1,0},
                    {-4,4,3,2},
                    {1,2,3,4}};
  vector<vector<int> > matrix;
  for (int i = 0; i < 4; i++)
    matrix.push_back(vector<int>(data[i], data[i]+4));
  cout << (new maximum_sum_rectangular::Solution())->getMaximumSumRectangular(matrix);
}
