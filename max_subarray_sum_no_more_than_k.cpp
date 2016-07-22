/**
 * Given an array of integers A and an integer k, find a subarray that contains the largest sum, subject to a constraint that the sum is less than k?
 *
 *solution: use a set<int> to record the cumulative sum from index 0. When processing index i, use
 * set.lower_bound(sum - k) to find the iterator that *iterator >= sum - k. Then update the ans when
 * sum - *iterator is bigger than ans.
 *
 *time complexity: O(nlogn)
 *space complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

namespace max_subarray_sum_no_more_than_k {
class Solution {
 public:
  int maxSubarray(vector<int>& nums, int k) {
    set<int> record;
    int ans = INT_MIN;
    int sum = 0;
    for (auto num : nums) {
      sum += num;
      auto iter = record.lower_bound(sum - k);
      if (iter != record.end() && sum - *iter > ans)
          ans = sum - *iter;
      if (sum <= k && sum > ans)
          ans = sum;
      record.insert(sum);
    }
    return ans;
  }
};
}

int main_max_subarray_sum_no_more_than_k() {
  int data[] = {1,2,2,4};
  vector<int> nums(data, data+4);
  cout << (new max_subarray_sum_no_more_than_k::Solution())->maxSubarray(nums, 8);
}
