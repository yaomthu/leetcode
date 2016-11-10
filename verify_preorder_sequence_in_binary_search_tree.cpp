/**
 * Verify preorder sequence in binary search tree
 * Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?
reuse the given preorder array.

time complexity: (n)
space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

namespace verify_preorder_sequence_in_binary_search_tree {
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty())
            return true;
        stack<int> record;
        int curMax = INT_MIN;
        for (auto num : preorder) {
            while (record.size() && record.top() < num) {
                if (record.top() > curMax)
                    curMax = record.top();
                record.pop();
            }
            if (num < curMax)
                return false;
            record.push(num);
        }
        return true;
    }
};

class SolutionFollowUp {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty())
            return true;
        int curMax = INT_MIN;
        int index = -1;
        for (int i = 0; i < preorder.size(); i++) {
            while (index >= 0 && preorder[index] < preorder[i]) {
                curMax = preorder[index--];
            }
            if (preorder[i] < curMax)
                return false;
            preorder[++index] = preorder[i];
        }
        return true;
    }
};
}
