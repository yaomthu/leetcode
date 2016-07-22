/**
 * Largest Divisible subset
 * Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]

solution: 首先对nums数组进行排序，dp[i] 记录从以nums[i]为结尾的满足条件的subset的长度，parents[i] 记录以[i]为结尾
的subset的上一跳信息。
time complexity: O(n^2)
space complexity: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace largest_divisible_subset {
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        if (nums.empty())
            return ans;
        vector<int> parents(nums.size(), -1);
        vector<int> dp(nums.size(), 1);
        sort(nums.begin(), nums.end());
        int index = 0;
        int curMax = 1;
        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < i; j++)
                if (nums[i]%nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parents[i] = j;
                    if (dp[i] > curMax) {
                        curMax = dp[i];
                        index = i;
                    }
                }
        while (index >= 0) {
            ans.push_back(nums[index]);
            index = parents[index];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
}
