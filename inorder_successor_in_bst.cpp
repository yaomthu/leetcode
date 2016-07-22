/**
 * Inorder successor in bst
 * Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.

Show Company Tags
Show Tags
Show Similar Problems
 *
 *
 solution: 如果p存在右孩子最好办。否则，记录从roog到p的路径，然后从后往前沿着路劲寻找后一个节点是前一个节点的左孩子。
 */

#include <iostream>
#include <vector>
using namespace std;

namespace inorder_successor_in_bst {
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p)
            return NULL;
        if (p->right) {
            TreeNode* cur = p->right;
            while (cur->left) {
                cur = cur->left;
            }
            return cur;
        } else {
            TreeNode* cur = root;
            vector<TreeNode*> record;
            while (cur != p) {
                record.push_back(cur);
                if (cur->val < p->val)
                    cur = cur->right;
                else
                    cur = cur->left;
            }
            while (record.size() && record.back()->right == cur) {
                cur = record.back();
                record.pop_back();
            }
            return record.empty()? NULL : record.back();
        }
    }
};
}
