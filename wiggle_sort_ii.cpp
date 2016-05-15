/**
 * Wiggle Sort II
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

solution: 首先找到数组nums的中位数mid，然后把数组里大于mid的数放到nums[odd]，把小于mid的数放到nums[even]。需要先
数组映射成  A    0  1  2  3  4  5
         nums  1  3  5  0  2  4
这样对数组A进行操作即可。

time complexity: O(n)
space complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace wiggle_sort_ii {
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty()) return;
        int n = nums.size();
        auto midptr = nums.begin()+n/2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        #define A(i) nums[(1+2*(i))%(n|1)]
        int i = -1, j = 0, k = n;
        while (j < k) {
            if (A(j) > mid && (++i != j))
                swap(A(i), A(j));
            else if (A(j) < mid && (--k != j))
                swap(A(j), A(k));
            else
                j++;
        }
    }
};
}

int main_wiggle_sort_ii() {
  int data[] = {1,1,2,2,2,1};
  vector<int> nums(data, data+6);
  (new wiggle_sort_ii::Solution())->wiggleSort(nums);
  for (auto num : nums) {
    cout << num << " ";
  }
}
