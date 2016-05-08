/**
 * House Robber III
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.

solution 1: 递归解法，在每个节点计算两个值(maxi, maxi_without)。maxi是以该节点为root的子树的最大收益，maxi_without是以该节点为root的子树在
不抢劫该节点时的最大值，maxi_without <= maxi。
time complexity: O(n).
   O(n) = 3+2*O(n/2) = 3+2*(3+2(n/4)) = .... = 3(1+2+2^2+...+2^(l-1)) + O(1)= O(n)
space complexity: O(n).
 */
#include <iostream>
using namespace std;

namespace house_robber_iii {
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        int maxi_without, maxi;
        dfs(root, maxi_without, maxi);
        return maxi;
    }
    void dfs(TreeNode* root, int& maxi_without, int& maxi) {
        if(!root) {
            maxi_without = 0;
            maxi = 0;
            return;
        }
        int left_maxi_without, left_maxi, right_maxi_without, right_maxi;
        dfs(root->left, left_maxi_without, left_maxi);
        dfs(root->right, right_maxi_without, right_maxi);
        maxi_without = left_maxi + right_maxi;
        int maxi_with = root->val + left_maxi_without + right_maxi_without;
        maxi = maxi_without > maxi_with? maxi_without : maxi_with;
    }
};
}
