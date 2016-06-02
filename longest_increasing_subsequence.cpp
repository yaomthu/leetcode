/**
 * Longest incrasing subsequence
 * Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

solution: 使用minSub数组，minSub[i]记录递增序列长度为i时最后一个元素的最小值，因此minSub[i] < minSub[j] (i < j).
利用minSub数组单调递增性，可以使用二分查找方法来寻找当前元素所对应的最长递增序列长度，并更新minSub信息。
time complexity: O(nlogn)
space complexity: O(n)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace longest_incrasing_subsequence {
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> minSub(1, INT_MIN);
        for (auto num : nums) {
            int index = findIndex(minSub, num);
            if (index == minSub.size()) {
                minSub.push_back(num);
            } else {
                if (minSub[index] > num)
                    minSub[index] = num;
            }
        }
        return minSub.size()-1;
    }
    int findIndex(vector<int>& nums, int num) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right)/2;
            if (nums[mid] >= num)
                right = mid-1;
            else
                left = mid+1;
        }
        return left;
    }
};
}

int main_longest_increasing_subsequence() {
  int data[] = {10, 9, 2, 5, 3, 7, 101, 18};
  vector<int> nums(data, data+8);
  cout << (new longest_incrasing_subsequence::Solution())->lengthOfLIS(nums);
}
