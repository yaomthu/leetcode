/**
 * Combination sum iv
 * Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:

What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
We can make each elements of the array to be greater than 0 first and add the target, then use the
same method.

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
solution: dynamic programing. dp[value] is used to record the total number of combinations whose sum
is equal to value. dp[value] = sum(dp[value - nums[i]]).
Solution1 use vector, time complexity: O(target * |nums|), space complexity: O(target)
Solution2 use hashmap, time complexity: O(target * |nums|), space complexity is better than O(target)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace combination_sum_iv {
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int value = 1; value <= target; value++) {
            for (int i = 0; i < nums.size(); i++) {
                if (value >= nums[i]) {
                    dp[value] += dp[value - nums[i]];
                }
            }
        }
        return dp[target];
    }
};
class Solution2 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int,int> record;
        record[0] = 1;
        for (int value = 1; value <= target; value++) {
            for (int i = 0; i < nums.size(); i++) {
                if (value >= nums[i] && record.find(value - nums[i]) != record.end()) {
                    if (record.find(value) == record.end()) {
                        record[value] = 0;
                    }
                    record[value] += record[value-nums[i]];
                }
            }
        }
        return record.find(target) == record.end()? 0 : record[target];
    }
};
}
