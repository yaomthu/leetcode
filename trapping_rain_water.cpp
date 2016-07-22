/**
 * Trapping train water
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace trapping_rain_water {
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int left = 0, right = height.size();
        int maxLeft = 0, maxRight = 0;
        int ans = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] > maxLeft)
                    maxLeft = height[left];
                else
                    ans += (maxLeft - height[left]);
                left++;
            } else {
                if (height[right] > maxRight)
                    maxRight = height[right];
                else
                    ans += (maxRight - height[right]);
                right--;
            }
        }
        return ans;
    }
};
}

int main_trapping() {
  int data[] = {5,4,1,2};
  vector<int> height(data, data+4);
  cout << (new trapping_rain_water::Solution())->trap(height);
}
