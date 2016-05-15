/**
 * Increasing Triplet Subsequence
 *Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

 *solution: 使用额外数组dp，如果nums[i] < nums[j] (j>i)，则dp[i] = true, 否则dp[i] = false. max_from_right记录
 *          从右往左遍历数组时当前的最大值。借助max_from_right, dp数组获取复杂度为O(n)。基于dp数组，我们从右往左再遍历
 *          数组，同时更新max_from_right，时间复杂度为O(n).
 *time complexity: O(n).
 *space complexity: O(n).
 */
#include <iostream>
#include <vector>
using namespace std;

namespace increasing_triplet_subsequence {
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        vector<bool> dp(nums.size(), false);
        dp[nums.size()-1] = false;
        int max_from_right = nums.back();
        for (int i=nums.size()-2; i>=0; i--) {
            if(nums[i] < max_from_right)
                dp[i] = true;
            else if (nums[i] > max_from_right)
                max_from_right = nums[i];
        }
        int index = nums.size()-1;
        while (index >= 0 && dp[index] == false)
            index--;
        if (index < 0)
            return false;
        max_from_right = nums[index];
        index--;
        while (index >= 0) {
            if (nums[index] < max_from_right)
                return true;
            else if(nums[index] > max_from_right && dp[index] == true)
                max_from_right = nums[index];
            index--;
        }
        return false;
    }
};
}

int main_increasing_triplet_subsequence() {
  vector<int> nums(5, 0);
  for (int i=0; i<nums.size(); i++)
    nums[i] = i;
  if ((new increasing_triplet_subsequence::Solution())->increasingTriplet(nums))
    cout << "true";
  else
    cout << "false";
}
