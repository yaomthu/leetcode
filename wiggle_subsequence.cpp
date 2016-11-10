/**
 * wiggle subsequence
 * A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?

Credits:
Special thanks to @agave and @StefanPochmann for adding this problem and creating all test cases.

solution1: dynamic programing. Use minEnd[i] to record the maximum length that ends with nums[i] and nums[i] is smaller than
previous element of the longest subsequence. maxEnd[i] to record the maximum length that that ends with
nums[i] and nums[i] is larger than the previous element of the longest subsequence.
time complexity: O(n^2)
space complexity: O(n)

solution2: greedy solution. Use bool increase to represent the previous difference is positive or negative.
time complexity: O(n)
space complexity: (1)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace wiggle_subsequence {
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> maxEnd(n, 1), minEnd(n, 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j] && minEnd[j] + 1 > maxEnd[i]) {
                    maxEnd[i] = minEnd[j] + 1;
                }
                if (nums[i] < nums[j] && maxEnd[j] + 1 > minEnd[i]) {
                    minEnd[i] = maxEnd[j] + 1;
                }
            }
        }
        return maxEnd[n-1] > minEnd[n-1]? maxEnd[n-1] : minEnd[n-1];
    }
};

class Solution2 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        bool increase;
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1] && (ans == 1 || increase == false)) {
                ans++;
                increase = true;
            } else if (nums[i] < nums[i-1] && (ans == 1 || increase == true)) {
                ans++;
                increase = false;
            }
        }
        return ans;
    }
};
}
