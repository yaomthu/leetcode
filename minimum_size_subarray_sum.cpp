/**
 * Minimum size subarray sum
 * Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

solution: 前后index
time complexity: O(n)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace minimum_size_subarray_sum {
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int start = 0, end = 0;
        int sum =  0;
        int ans = INT_MAX;
        while (end < nums.size()) {
            while (end < nums.size() && sum < s) {
                sum += nums[end];
                end++;
            }
            if (sum >= s) {
                while (start < end && sum >= s) {
                    sum -= nums[start];
                    start++;
                }
                if (ans > end-start+1)
                    ans = end-start+1;
            }
        }
        if (ans == INT_MAX)
            return 0;
        else
            return ans;
    }
};
}
