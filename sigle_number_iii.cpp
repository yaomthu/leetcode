/**
 * Single number iii
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 *
 *solution: 记住，result & (-result)可以去到result的二进制表示里的最后一位'1'.
 */

#include <iostream>
#include <vector>
using namespace std;

namespace single_number_iii {
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto num : nums)
            result ^= num;
        int dis = result & (-result);
        int res1 = 0, res2 = 0;
        for (auto num : nums) {
            if ((num & dis) != 0)
                res1 ^= num;
            else
                res2 ^= num;
        }
        vector<int> ans;
        ans.push_back(res1);
        ans.push_back(res2);
        return ans;
    }
};
}
