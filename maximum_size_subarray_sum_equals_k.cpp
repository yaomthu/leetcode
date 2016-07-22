/**
 * Maximum size subarray sum equals to k
 * Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace maximum_size_subarrays_sum_equals_to_k {
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty())
            return 0;
        unordered_map<int, int> record;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k && ans < i + 1)
                ans = i + 1;
            if (record.find(sum - k) != record.end()) {
                if (i - record[sum-k] > ans)
                    ans = i - record[sum-k];
            }
            if (record.find(sum) == record.end())
                record[sum] = i;
        }
        return ans;
    }
};
}
