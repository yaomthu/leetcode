/**
 * Find peak element
 * A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

 solution: 记得考虑right-left == 1的情况。
 */

#include <iostream>
#include <vector>
using namespace std;

namespace find_peak_element {
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            if (left == right)
                return left;
            if (right - left == 1)
                return nums[left]>nums[right]? left : right;
            int mid = (left+right)/2;
            if (nums[mid] > nums[mid+1]) {
                if (nums[mid] > nums[mid-1])
                    return mid;
                else
                    right = mid;
            } else {
                left = mid;
            }
        }
        return 0;
    }
};
}
