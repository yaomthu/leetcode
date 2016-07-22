/**
 * House robber
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

Subscribe to see which companies asked this question

solution: dp method. cache[i] 记录0到i之间rob的最大价值。
cache[i] = max{cache[i-2]+nums[i], cache[i-1]}
 */

#include <iostream>
#include <vector>
using namespace std;

namespace hourse_robber {
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> cache(nums.size(), 0);
        cache[0] = nums[0];
        cache[1] = nums[1]>cache[0]? nums[1]: cache[0];
        for (int i=2; i<nums.size(); i++) {
            cache[i] = cache[i-2] + nums[i];
            cache[i] = cache[i]>cache[i-1]? cache[i]: cache[i-1];
        }
        return cache.back();
    }
};
}
