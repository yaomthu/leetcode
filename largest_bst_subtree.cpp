/**
 * Largest BST subtree
 * Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \
 1   8   7
The Largest BST Subtree in this case is the highlighted one.
The return value is the subtree's size, which is 3.
Show Hint
Follow up:
Can you figure out ways to solve it with O(n) time complexity?
 */

#include <iostream>
using namespace std;

namespace largest_bst_substree {
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct Result {
        int size;
        int lower;
        int upper;
        Result(int s, int l, int u) : size(s), lower(l), upper(u) {}
    };
    int largestBSTSubtree(TreeNode* root) {
        if (!root)
            return 0;
        int ans = 1;
        dfs(root, ans);
        return ans;
    }
    Result dfs(TreeNode* root, int& ans) {
        if (!root) {
            return Result(0, INT_MAX, INT_MIN);
        }
        Result leftResult = dfs(root->left, ans);
        Result rightResult = dfs(root->right, ans);
        if (leftResult.size == -1 || rightResult.size == -1 || root->val <= leftResult.upper || root->val >= rightResult.lower)
            return Result(-1, 0, 0);
        int size = leftResult.size + 1 + rightResult.size;
        if (ans < size)
            ans = size;
        int lower = leftResult.lower < root->val? leftResult.lower : root->val;
        int upper = rightResult.upper > root->val? rightResult.upper : root->val;
        return Result(size, lower, upper);
    }
};
}
