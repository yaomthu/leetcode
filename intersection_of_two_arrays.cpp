/**
 * Intersection of Two Arrays
 * Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
Subscribe to see which companies asked this question

solution: 使用hashset记录nums1数组，然后再去遍历nums2数组。
time complexity: O(n)
space complexity: O(n)
 */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

namespace intersection_of_two_arrays {
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (nums1.empty() || nums2.empty())
            return ans;
        unordered_set<int> record;
        for (int i=0; i<nums1.size(); i++)
            record.insert(nums1[i]);
        for (int i=0; i<nums2.size(); i++) {
            if (record.find(nums2[i]) != record.end()) {
                ans.push_back(nums2[i]);
                record.erase(nums2[i]);
            }
        }
        return ans;
    }
};
}

int main_intersection_of_two_arrays() {
  int data1[] = {1,2,2,1};
  int data2[] = {2,2};
  vector<int> nums1(data1, data1+4);
  vector<int> nums2(data2, data2+2);
  vector<int> ans = (new intersection_of_two_arrays::Solution())->intersection(nums1, nums2);
  for (int num : ans)
    cout << num << " ";
}
