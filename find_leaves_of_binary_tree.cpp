/**
 * Find leaves of binary tree
 * Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree
          1
         / \
        2   3
       / \
      4   5
Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:

          1
         /
        2
2. Now removing the leaf [2] would result in this tree:

          1
3. Now removing the leaf [1] would result in the empty tree:

          []
Returns [4, 5, 3], [2], [1].
solution: 递归方法，叶子节点为第一层，从最下往上层数增加。
time complexity: O(n)
space complexity: O(logn)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace find_leaves_of_binary_tree {
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > findLeaves(TreeNode* root) {
        vector<vector<int> > ans;
        if (!root)
            return ans;
        dfs(root, ans);
        return ans;
    }
    int dfs(TreeNode* root, vector<vector<int> >& ans) {
        if (!root) {
            return 0;
        }
        int leftLayer = dfs(root->left, ans);
        int rightLayer = dfs(root->right, ans);
        int layer = leftLayer > rightLayer ? 1 + leftLayer : 1 + rightLayer;
        if (layer > ans.size()) {
            ans.push_back(vector<int>());
        }
        ans[layer-1].push_back(root->val);
        return layer;
    }
};
}
