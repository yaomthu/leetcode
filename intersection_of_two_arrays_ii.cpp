/**
 * Intersection of Two Arrays II
 * Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

solution: 使用hashmap记录nums1数组元素以及出现的次数，然后遍历nums2数组。
time complexity: O(n)
space complexity: O(n)

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
solution: 使用两个index i,j 来同时遍历数组nums1和nums2， 当nums1[i] == nums2[j]时,i++,j++; 当nums1[i] < nums2[j], i++; 否则 j++。
time complexity: O(n);
space complexity: O(1);
What if nums1's size is small compared to num2's size? Which algorithm is better?
solution：
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
solution: 如果nums1可以放入hashmap，则将nums1放入hashmap，将nums2以chunk形式读入内存做intersection操作。
如果nums1也不能放入内存，则对nums1和nums2分别进行外部排序，然后以chunk形式将nums1和nums2读入内存进行intersection操作。
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace intersection_of_two_arrays_ii {
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (nums1.empty() || nums2.empty())
            return ans;
        unordered_map<int,int> record;
        for (auto num : nums1)
            record[num]++;
        for (auto num : nums2) {
            if (record.find(num) != record.end()) {
                ans.push_back(num);
                record[num]--;
                if (record[num] == 0)
                    record.erase(num);
            }
        }
        return ans;
    }
};

class Followup1 {
  public:
     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       int i = 0, j = 0;
       vector<int> ans;
       while (i < nums1.size() && j < nums2.size()) {
         if (nums1[i] == nums2[j]) {
           ans.push_back(nums1[i]);
           i++;
           j++;
         } else if (nums1[i] < nums2[j])
           i++;
         else
           j++;
       }
       return ans;
     }
};
}

int main_intersection_of_two_arrays_ii() {
  int data1[] = {1,1,2,2};
  int data2[] = {1,2,3};
  vector<int> nums1(data1, data1+4);
  vector<int> nums2(data2, data2+3);
  vector<int> ans = (new intersection_of_two_arrays_ii::Followup1())->intersect(nums1, nums2);
  for (auto num : ans)
    cout << num << " ";

}
