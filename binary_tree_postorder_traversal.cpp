/**
 * Binary tree postorder traversal
 * Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
 *
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

namespace binary_tree_postorder_traversal {
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode*> nodes;
        nodes.push(root);
        TreeNode* pre = NULL;
        while (nodes.size()) {
            TreeNode* cur = nodes.top();
            if ((!cur->left && !cur->right) || (pre && (pre == cur->left || pre == cur->right))) {
                nodes.pop();
                ans.push_back(cur->val);
                pre = cur;
            } else {
                if (cur->right)
                    nodes.push(cur->right);
                if (cur->left)
                    nodes.push(cur->left);
            }
        }
        return ans;
    }
};
}
