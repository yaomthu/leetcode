/**
 * Range addition
 * Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]
Explanation:

Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
Show Hint
Credits

solution: 对于每个update，ans[update[0]] += update[2], ans[update[1]+1] -= update[2]. 之后再前
往后遍历ans数组，并将累积和赋值给每个元素。
time complexity: O(max(k, n))
space complexity: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace range_addition {
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int> >& updates) {
        vector<int> ans(length, 0);
        for (auto update : updates) {
            ans[update[0]] += update[2];
            if (update[1] + 1 < ans.size())
                ans[update[1] + 1] -= update[2];
        }
        int sum = 0;
        for (int i = 0; i < ans.size(); i++) {
            sum += ans[i];
            ans[i] = sum;
        }
        return ans;
    }
};
}
