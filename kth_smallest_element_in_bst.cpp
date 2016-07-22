/**
 * Kth smallest element in BST
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

solution 1: 中序遍历二叉树
time complexity: O(n)
space complexity: O(logn)

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 solution 2: 新建一棵二叉树，每个点多一个域children来记录孩子+自己的数量。
search complexity : O(logk)


 */

#include <iostream>
#include <stack>
using namespace std;

namespace kth_smallest_element_in_bst {
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return 0;
        stack<TreeNode*> nodes;
        int num = 0;
        while (nodes.size() || root) {
            while (root) {
                nodes.push(root);
                root = root->left;
            }
            if (nodes.size()) {
                root = nodes.top();
                nodes.pop();
                num++;
                if (num == k)
                    return root->val;
                root = root->right;
            }
        }
        return 0;
    }
};

class Solution_Followup {
public:
    struct newTreeNode {
        int val;
        int children;
        newTreeNode* left;
        newTreeNode* right;
        newTreeNode(int val_): val(val_), children(1), left(NULL), right(NULL) {}
    };
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return 0;
        newTreeNode* newRoot = buildNewTree(root);
        while (newRoot) {
            if (newRoot->left) {
                if (k == newRoot->left->children+1)
                    return newRoot->val;
                else if (k <= newRoot->left->children)
                    newRoot = newRoot->left;
                else {
                    k -= (newRoot->left->children+1);
                    newRoot = newRoot->right;
                }
            } else {
                if (k == 1)
                    return newRoot->val;
                else {
                    k -= 1;
                    newRoot = newRoot->right;
                }
            }
        }
        return 0;
    }
    newTreeNode* buildNewTree(TreeNode* root) {
        newTreeNode* newRoot = new newTreeNode(root->val);
        if (root->left) {
            newRoot->left = buildNewTree(root->left);
            newRoot->children += newRoot->left->children;
        }
        if (root->right) {
            newRoot->right = buildNewTree(root->right);
            newRoot->children += newRoot->right->children;
        }
        return newRoot;
    }
};
}
