/**
 * Contain duplicate iii
 * Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

Subscribe to see which companies asked this question
 *
 *
 *solution: 使用multiset来记录窗口数据，使用multiset.lower_bound(nums[i]-t) 来找到 >= nums[i]-t 的iterator。
 *time complexity: O(nlogk)
 *space complexity: O(k)
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

namespace contain_duplicate_iii {
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k <= 0 || t < 0)
            return false;
        multiset<int> window;
        for (int i=0; i<nums.size(); i++) {
            auto ptr = window.lower_bound(nums[i]-t);
            if (ptr != window.end() && abs(*ptr-nums[i]) <= t)
                return true;
            if (window.size() == k)
                window.erase(nums[i-k]);
            window.insert(nums[i]);
        }
        return false;
    }
};
}
