/**
 * House robber ii
 * Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the

 solution: dp method, 可将该问题分解为[0~n-2]的最优方案与[1~n-1]的最优方案比较。cache[i] 记录start到i之间rob的最大价值。
cache[i] = max{cache[i-2]+nums[i], cache[i-1]}
 time complexity: O(n)
 space complexity: O(n)
 */
#include <iostream>
#include <vector>
using namespace std;

namespace house_robber_ii {
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return  nums[0];
        int a = rob(nums, 0, nums.size()-2);
        int b = rob(nums, 1, nums.size()-1);
        return a>b? a: b;
    }
    int rob(vector<int>& nums, int start, int end) {
        vector<int> cache(nums.size(), 0);
        cache[start] = nums[start];
        cache[start+1] = nums[start+1] > cache[start]? nums[start+1]: cache[start];
        for (int i=start+2; i<=end; i++) {
            cache[i] = cache[i-2] + nums[i];
            cache[i] = cache[i-1]>cache[i]? cache[i-1]: cache[i];
        }
        return cache[end];
    }
};
}
