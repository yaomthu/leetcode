/**
 * Maximum gap
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.

 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace maximum_gap {
class Solution {
public:
    struct Bucket {
        int bottom;
        int up;
        Bucket() : bottom(INT_MAX), up(INT_MIN) {}
    };
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        if (nums.size() == 2)
            return abs(nums[0]-nums[1]);
        int small = INT_MAX, big = INT_MIN;
        for (auto num : nums) {
            if (num < small)
                small = num;
            if (num > big)
                big = num;
        }
        if (small == big)
            return 0;
        int k = nums.size()-1;
        vector<Bucket> buckets(k, Bucket());
        buckets[0].bottom = buckets[0].up = small;
        buckets[k-1].bottom = buckets[k-1].up = big;
        float dis = (float)(big-small)/k;
        for (auto num : nums) {
            int index = (num-small)/dis;
            if (index >= k)
                index = k - 1;
            if (buckets[index].up < num)
                buckets[index].up = num;
            if (buckets[index].bottom > num)
                buckets[index].bottom = num;
        }
        int start = 0;
        int ans = 0;
        while (start < buckets.size()) {
            int end = start + 1;
            while (end < buckets.size() && buckets[end].bottom == INT_MAX)
                end++;
            if (buckets[end].bottom - buckets[start].up > ans)
                ans = buckets[end].bottom - buckets[start].up;
            start = end;
        }
        return ans;
    }
};
}

int main_maximum_gap() {
  int data[] = {3,6,9,1};
  vector<int> nums(data, data+4);
  cout << (new maximum_gap::Solution())->maximumGap(nums);
}
