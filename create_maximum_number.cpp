/**
 * Create Maximum Number
 * Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]

solution: 遍历所有可能的(len1, len2)组合，其中Len1是从nums1取出的数字个数，len2是从nums2取出的数字个数。实现
pickup函数从一个数组里取出len个数，使得它的值最大。实现merge函数来合并两个子数组。

time complexity: O(k*n)
space complexity: O(k)

 */

#include <iostream>
#include <vector>
using namespace std;

namespace create_maximum_number {
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0 || nums1.size()+nums2.size() < k)
            return vector<int>();
        vector<int> ans(k, 0);
        for (int len1 = 0; len1<=k && len1<=nums1.size(); len1++) {
            int len2 = k-len1;
            vector<int> array1 = pickup(nums1, len1);
            vector<int> array2 = pickup(nums2, len2);
            vector<int> mergeArray = merge(array1, array2);
            if (compare(ans, 0, mergeArray, 0) == false) {
                for (int i=0; i<ans.size(); i++)
                    ans[i] = mergeArray[i];
            }
        }
        return ans;
    }
    vector<int> pickup(vector<int>& nums, int len) {
        vector<int> ans;
        if (len == 0)
            return ans;
        int index = 0;
        while (index < nums.size()) {
            if (index == 0 || nums[index] <= ans.back() || ans.size()+(nums.size()-index) <= len) {
              ans.push_back(nums[index]);
              index++;
            } else {
                ans.pop_back();
            }
        }
        return ans;
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i = 0, j = 0;
        while (i<nums1.size() && j<nums2.size()) {
            if (compare(nums1, i, nums2, j) == true)
                ans.push_back(nums1[i++]);
            else
                ans.push_back(nums2[j++]);
        }
        while (i < nums1.size())
            ans.push_back(nums1[i++]);
        while (j < nums2.size())
            ans.push_back(nums2[j++]);
        return ans;
    }
    bool compare(vector<int>& nums1, int s1, vector<int>& nums2, int s2) {
        int i = s1, j = s2;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j])
                return true;
            else if (nums1[i] < nums2[j])
                return false;
            i++;
            j++;
        }
        return i == nums1.size()? false : true;
    }
};
}

int main_create_maximum_number() {
  int data1[] = {6,7};
  int data2[] = {6,0,4};
  vector<int> nums1(data1, data1+2);
  vector<int> nums2(data2, data2+3);
  vector<int> ans = (new create_maximum_number::Solution())->maxNumber(nums1, nums2, 3);
  for (auto num : ans) {
    cout << num << " ";
  }
  cout << "end" << endl;
}
