/**
 * Sort transform array
 * Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

namespace sort_transorm_array {
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (nums.empty())
            return vector<int>();
        vector<int> ans(nums.size(), 0);
        if (a == 0) {
            if (b == 0) {
                for (int i = 0; i < ans.size(); i++)
                    ans[i] = c;
            } else if (b > 0) {
                for (int i = 0; i < ans.size(); i++) {
                    ans[i] = b * nums[i] + c;
                }
            } else {
                for (int i = 0; i < ans.size(); i++) {
                    ans[i] = b * nums[ans.size()-i-1] + c;
                }
            }
        } else if (a < 0) {
            int left = findIndex(nums, a, b);
            int right = left + 1;
            int index = ans.size() - 1;
            while (left >= 0 && right < nums.size()) {
                if (abs(nums[left] + (float)b/(2*a)) < abs(nums[right] + (float)b/(2*a))) {
                    ans[index--] = a*nums[left]*nums[left] + b*nums[left] + c;
                    left--;
                } else {
                    ans[index--] = a*nums[right]*nums[right] + b*nums[right] + c;
                    right++;
                }
            }
            while (left >= 0) {
                ans[index--] = a*nums[left]*nums[left] + b*nums[left] + c;
                left--;
            }
            while (right < ans.size()) {
                ans[index--] = a*nums[right]*nums[right] + b*nums[right] + c;
                right++;
            }
        } else {
            int left = findIndex(nums, a, b);
            int right = left + 1;
            int index = 0;
            while (left >= 0 && right < nums.size()) {
                if (abs(nums[left] + (float)b/(2*a)) < abs(nums[right] + (float)b/(2*a))) {
                    ans[index++] = a*nums[left]*nums[left] + b*nums[left] + c;
                    left--;
                } else {
                    ans[index++] = a*nums[right]*nums[right] + b*nums[right] + c;
                    right++;
                }
            }
            while (left >= 0) {
                ans[index++] = a*nums[left]*nums[left] + b*nums[left] + c;
                left--;
            }
            while (right < ans.size()) {
                ans[index++] = a*nums[right]*nums[right] + b*nums[right] + c;
                right++;
            }
        }
        return ans;
    }
    int findIndex(vector<int>& nums, int a, int b) {
        int index = -1;
        float dis = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i] + (float)b/(2*a)) < dis) {
                dis = abs(nums[i] + (float)b/(2*a));
                index = i;
            }
        }
        return index;
    }
};
}
