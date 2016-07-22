/**
 * Sliding window maximum
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

Solution: 使用双端队列来解题。
time complexity: O(n)
space complexity: O(k)
 */

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

namespace sliding_window_maximum {
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.empty())
            return ans;
        deque<int> window;
        for (int i=0; i<nums.size(); i++) {
            while (window.size() && window.back() < nums[i])
                window.pop_back();
            window.push_back(nums[i]);
            if (i >= k-1) {
                ans.push_back(window.front());
                if (nums[i-k+1] == window.front())
                    window.pop_front();
            }
        }
        return ans;
    }
};
}

int main_sliding_window_maximum() {
  int data[] = {1,3,-1,-3,5,3,6,7};
  vector<int> nums(data, data+8);
  vector<int> ans = (new sliding_window_maximum::Solution())->maxSlidingWindow(nums, 3);
  for (auto num : ans)
    cout << num << " ";
}
