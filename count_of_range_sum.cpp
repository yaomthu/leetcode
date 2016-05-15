/**
 * Count of Range Sum
 * Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

solution: 首先获得sum数组，然后使用归并排序算法对sum数组排序，在归并两个数组A和B前先统计符合条件的对数。统计方法是遍历
数组A的每个元素，统计数组B里有多少个元素符合。记得提高统计效率。
time complexity : O(nlogn)
space complexity : O(n)

 */
#include <iostream>
#include <vector>
using namespace std;

namespace count_of_range_sum {
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty())
            return 0;
        vector<long long> sums(nums.size(), 0);
        for (int i=0; i<nums.size(); i++) {
            if (i == 0)
                sums[i] = nums[i];
            else
                sums[i] = sums[i-1]+nums[i];
        }
        return mergeSort(sums, lower, upper, 0, sums.size()-1);
    }
    int mergeSort(vector<long long>& sums, int lower, int upper, int start, int end) {
        if (start == end) {
            if (sums[start] >= lower && sums[start] <= upper)
                return 1;
            else
                return 0;
        }
        int mid = (start+end)/2;
        int ans = mergeSort(sums, lower, upper, start, mid) + mergeSort(sums, lower, upper, mid+1, end);
        int j = mid + 1;
        for (int i=start; i<=mid; i++) {
            while (j <= end && sums[j] - sums[i] < lower)
                j++;
            int k = j;
            while (k <= end && sums[k] - sums[i] <= upper)
                k++;
            ans += (k-j);
        }
        vector<long long> temp(end-start+1, 0);
        int i = mid, index = end-start;
        j = end;
        while (i >= start && j >= mid+1) {
            if (sums[i] > sums[j])
                temp[index--] = sums[i--];
            else
                temp[index--] = sums[j--];
        }
        while (i >= start)
            temp[index--] = sums[i--];
        while (j >= mid+1)
            temp[index--] = sums[j--];

        for (i = start, index = 0; i<=end; i++, index++) {
            sums[i] = temp[index];
        }
        return ans;
    }
};
}

int main_count_of_range_sum() {
  int data[] = {-2, 5, -1};
  vector<int> nums(data, data+3);
  cout << (new count_of_range_sum::Solution())->countRangeSum(nums, -2, 2);
}
