/**
 * Find the duplicate number
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Solution: 将该数值想象成链表，每个元素的值为下一跳的地址。这样使用快慢下标来寻找环的起始位置。
time complexity: O(n)
space complexity: O(1)

Solution 1: 在数值范围[1, n]之间进行二分搜索，每次选中mid，统计整个数组在数值[left, mid]之间的元素个数，如果个数
小于等于mid-left+1, 说明[mid,right]之间必然存在重复元素 (ps: [left, mid]之间可能也有)。
time complexity: O(nlogn)
space complexity: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;
namespace find_the_duplicate_number {
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

class Solution2 {
 public:
     int findDuplicate(vector<int>& nums) {
         int left = 1, right = nums.size()-1;
         while (left <= right) {
             int mid = (left+right)/2;
             if (count(nums, left, mid) <= mid-left+1)
                 left = mid+1;
             else {
                 if (left == mid)
                     break;
                 else
                     right = mid;
             }
         }
         return left;
     }

     int count(vector<int>& nums, int a, int b) {
         int ans = 0;
         for (auto num : nums) {
             if (num >= a && num <= b)
                 ans++;
         }
         return ans;
     }
};
}

int main_find_the_duplicate_number() {
  int data[] = {1,2,1};
  vector<int> nums(data, data+3);
  cout << (new find_the_duplicate_number::Solution())->findDuplicate(nums);
}
