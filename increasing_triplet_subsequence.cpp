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
 *          如果不适用额外数组，则从右往左扫描每个元素，首先找到nums[index] < nums[index+1]，并记录下maxFromRight = max{nums[j]} (j >= index),
 *          middle = nums[index]，middle用于记录三个升序元素的中间那个。
 *          继续遍历剩下的元素，如果找到nums[index] < middle 就return true，否则条件满足时就更新middle 和 maxFromRight.
 *time complexity: O(n).
 *space complexity: O(1).
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
        int index = nums.size()-2;
        int maxFromRight = nums.back();
        while (index >= 0 && nums[index] >= nums[index+1]) {
            if (nums[index] > maxFromRight)
                maxFromRight = nums[index];
            index--;
        }
        if (index < 0)
            return false;
        int middle = nums[index--];
        while (index >= 0) {
            if (nums[index] < middle)
                return true;
            if (nums[index] > middle && nums[index] < maxFromRight)
                middle = nums[index];
            if (nums[index] > maxFromRight)
                maxFromRight = nums[index];
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
