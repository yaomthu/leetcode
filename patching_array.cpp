/**
 * Patching Array
 * Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

Example 1:
nums = [1, 3], n = 6
Return 1.

Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
nums = [1, 5, 10], n = 20
Return 2.
The two patches can be [2, 4].

Example 3:
nums = [1, 2, 2], n = 5
Return 0.

Solution: 遍历该数组，使用upper记录当前所能表示数的上界。当数组当前元素<=upper+1时，upper直接加上当前元素；否则，需要新引入（upper+1）这个数
同时将upper增加upper+1. 注意，在遍历数组时如果upper已经>=n时就要马上退出循环。
time complexity: O(n)
space complexity: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

namespace patching_array {
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long upper = 0;
        int ans = 0;
        int index = 0;
        while (index < nums.size() && upper < n) {
            if (nums[index] <= upper + 1) {
                upper += nums[index];
                index++;
            } else {
                ans++;
                upper += (upper+1);
            }
        }
        while (upper < n) {
            upper += upper+1;
            ans++;
        }
        return ans;
    }
};
}

int main_patching_array() {
  int array[] = {1,3};
  vector<int> nums(array, array+2);
  cout << (new patching_array::Solution())->minPatches(nums, 6);
}
