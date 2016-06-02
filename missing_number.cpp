/**
 * Missing number
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

solution 1: 改动原始数组, 挪动元素，一直到nums[i] = i.
time complexity : O(n)
space complexity : O(1)

solution 2: 不改动原始数组，使用 0-n 的总和减去数组实际元素之和即可得到缺失的数字。
time complexity : O(n)
space complexity: O(1)

solution 3: 类似于solution 2
time complexity : O(n)
space complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace missing_number {
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] != i && nums[i] < n) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i=0; i<n; i++)
            if (nums[i] != i)
                return i;
        return n;
    }
};

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] != i && nums[i] < n) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i=0; i<n; i++)
            if (nums[i] != i)
                return i;
        return n;
    }
};

class Solution3 {
 public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = 0, i = 0;
    for (; i<n; i++)
      sum += i-nums[i];
    return sum+i;
  }
};
}

int main_missing_number() {
  int data[] = {1,3,0};
  vector<int> nums(data, data+3);
  cout << (new missing_number::Solution())->missingNumber(nums);
}
