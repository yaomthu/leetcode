/**
 * Binary tree right side view
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

solution 1 : recursive method, 前序遍历的变种。

solution 2: iterative method，按层序遍历

 *
 */
#include <iostream>
#include <vector>
using namespace std;

namespace binary_tree_right_side_view {
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        dfs(ans, root, 1);
        return ans;
    }
    void dfs(vector<int>& ans, TreeNode* root, int level) {
        if (!root)
            return;
        if (ans.size() < level)
            ans.push_back(root->val);
        if (root->right)
            dfs(ans, root->right, level+1);
        if (root->left)
            dfs(ans, root->left, level+1);
    }
};
}
