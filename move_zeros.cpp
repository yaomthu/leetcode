/**
 * Move zeros
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

time complexity: O(n)
space complexity: O(1)

 */


#include <iostream>
#include <vector>
using namespace std;

namespace move_zeros {
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty())
            return;
        int index = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                index++;
                nums[index] = nums[i];
            }
        }
        index++;
        while (index < nums.size()) {
            nums[index++] = 0;
        }
    }
};
}

int main_move_zeros() {
  int data[] = {0,0,0,1,2,3};
  vector<int> nums(data, data+6);
  (new move_zeros::Solution())->moveZeroes(nums);
  for (auto num : nums)
    cout << num << " ";
}
