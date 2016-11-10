/**
 * Split array largest sum
 * Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
Given m satisfies the following constraint: 1 ≤ m ≤ length(nums) ≤ 14,000.

Examples:

Input:
nums = [1,2,3,4,5]
m = 2

Output:
9

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5],
where the largest sum among the two subarrays is only 9.
Subscribe to see which companies asked this question
 */

#include <iostream>
#include <vector>
using namespace std;

namespace split_array_largest_sum {
class DpSolution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<int> > dp(m+1, vector<int>(nums.size(), 0));
        vector<int> sub(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            sub[i] = i == 0? nums[i] : sub[i-1] + nums[i];
        }
        for (int i = 1; i <= m; i++) {
            if (i == 1) {
                for (int j = 0; j < nums.size(); j++) {
                    dp[i][j] = j == 0? nums[j] : dp[i][j-1] + nums[j];
                }
            } else {
                for (int j = i-1; j < nums.size() + i - m; j++) {
                    dp[i][j] = INT_MAX;
                    for (int k = i-2; k < j; k++) {
                        if (maxi(dp[i-1][k], sub[j] - sub[k]) < dp[i][j]) {
                            dp[i][j] = maxi(dp[i-1][k], sub[j] - sub[k]);
                        }
                    }
                }
            }
        }
        return dp[m][nums.size()-1];
    }
    int maxi(int a, int b) {
        return a > b? a : b;
    }
};

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (auto num : nums) {
            if (num > left) {
                left = num;
            }
            right += num;
        }
        long long ans;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (split(nums, m, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    bool split(vector<int>& nums, int m, long long target) {
        int index = 0;
        long long sum = 0;
        while (index < nums.size()) {
            if (sum + nums[index] > target) {
                sum = 0;
                m--;
            }
            sum += nums[index++];
        }
        return m >= 1;
    }
};
}

int main() {
  int data[] = {1,4,4};
  vector<int> nums(data, data+3);
  cout << (new split_array_largest_sum::Solution())->splitArray(nums, 3);
}
