/**
 * Product of array except itself
 * Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

Subscribe to see which companies asked this question
 */

#include <iostream>
#include <vector>
using namespace std;

namespace product_of_array_except_itself {
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty())
            return vector<int>();
        vector<int> ans(nums.size(), 1);
        for (int i = nums.size()-1; i >= 0; i--) {
            if (i == nums.size()-1)
                ans[i] = nums[i];
            else
                ans[i] = ans[i+1]*nums[i];
        }
        for (int i=1; i<nums.size(); i++) {
            nums[i] = nums[i-1] * nums[i];
        }
        for (int i = 0; i < ans.size(); i++) {
            if (i == 0)
                ans[i] = ans[i+1];
            else if (i == ans.size()-1)
                ans[i] = nums[i-1];
            else
                ans[i] = nums[i-1]*ans[i+1];
        }
        return ans;
    }
};
}

int main_product_of_array_except_itself() {
  int data[] = {1,2,3,4};
  vector<int> nums(data, data+4);
  vector<int> ans = (new product_of_array_except_itself::Solution)->productExceptSelf(nums);
  for (auto num : ans)
    cout << num << " ";
}
