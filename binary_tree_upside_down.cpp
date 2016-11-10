/**
 * Binary tree upside down
 * Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 */

#include <iostream>
#include <stack>
using namespace std;

namespace binary_tree_upside_down {
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root)
            return NULL;
        stack<TreeNode*> record;
        while (root) {
            record.push(root);
            root = root->left;
        }
        TreeNode* head = record.top();
        record.pop();
        TreeNode* cur = head;
        while (record.size()) {
            cur->left = (record.top())->right;
            cur->right = record.top();
            cur = record.top();
            record.pop();
        }
        cur->left = cur->right = NULL;
        return head;
    }
};
}
