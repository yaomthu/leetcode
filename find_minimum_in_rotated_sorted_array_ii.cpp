/**
 * Find minimum in Rotated sorted array ii
 * Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 */

#include <iostream>
#include <vector>
using namespace std;

namespace find_minimum_in_rotated_sorted_array_ii {
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        int left = 0, right = nums.size()-1;
        while(left <= right)
        {
            if(left == right) return nums[left];
            if(right-left == 1) return nums[left]<nums[right]? nums[left]: nums[right];
            int mid = (left+right)/2;
            if(nums[left] <= nums[mid])
            {
                if(nums[mid] < nums[right])
                    right = mid - 1;
                else if(nums[mid] == nums[right])
                    right--;
                else
                    left = mid + 1;
            }
            else
                right = mid;
        }
        return 0;
    }
};
}
