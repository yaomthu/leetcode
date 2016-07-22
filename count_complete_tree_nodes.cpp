/**
 * Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Subscribe to see which companies asked this question

solution_dfs: 从上往下判断每个节点为root的树是否为满完全二叉树，如果是，直接返回2^h-1。如果不是，再分别统计该节点的左右子数。
time complexity: O((logn)^2)
space complexity:O(logn)

solution_iterative: 计算二叉树的高度height，同时计算二叉树最后一层的叶子数。
统计叶子数时，当该节点的左子数高度与右子数高度相同时，说明子数树为满二叉树，且右子数含有最后一层的叶子节点。
如果左子数高度大于右子树高度，说明右子树里不含有最后一层的叶子节点。
如果某节点的右节点为空，则叶子数+1并退出循环。
 */

#include <iostream>
using namespace std;

namespace count_complete_tree_nodes {

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftHeight = getHeight(root, true);
        int rightHeight = getHeight(root, false);
        if (leftHeight == rightHeight)
            return (1<<leftHeight)-1;
        else
            return 1+countNodes(root->left)+countNodes(root->right);
    }
    int getHeight(TreeNode* root, bool type) {
        int depth = 0;
        while (root) {
            depth++;
            if (type)
                root = root->left;
            else
                root = root->right;
        }
        return depth;
    }
};

class Solution_iterative {
 public:
     int countNodes(TreeNode* root) {
         if (!root)
             return 0;
         int height = 0;
         int leaves = 0;
         while (true) {
             int leftHeight = getHeight(root->left);
             int rightHeight = getHeight(root->right);
             height = height>(leftHeight+1)? height: (leftHeight+1);
             if (!root->right) {
                 leaves++;
                 break;
             }
             if (leftHeight == rightHeight) {
                 leaves += 1<<(leftHeight-1);
                 root = root->right;
             } else {
                 root = root->left;
             }
         }
         return (1<<(height-1))-1+leaves;
     }
     int getHeight(TreeNode* root) {
         int depth = 0;
         while (root) {
             depth++;
             root = root->left;
         }
         return depth;
     }
};
}
