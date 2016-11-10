/**
 * Count univalue substree
 * Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.

Show Tags

time complexity: O(n)
space complexity: O(log n)
 *
 */

#include <iostream>
using namespace std;

namespace count_univalue_substree {
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (!root)
            return 0;
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    bool dfs(TreeNode* root, int& ans) {
        if (!root)
            return true;
        bool leftStatus = dfs(root->left, ans);
        bool rightStatus = dfs(root->right, ans);
        if (leftStatus && rightStatus) {
            if (root->left && root->val != root->left->val)
                return false;
            if (root->right && root->val != root->right->val)
                return false;
            ans++;
            return true;
        } else
            return false;
    }
};
}
