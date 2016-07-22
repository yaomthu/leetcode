/**
 * Binary tree longest consecutive sequence
 * Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    /
   2
  /
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

solution: dfs bottom to up.
time complexity: O(n)
space complexity: O(h)

solution2： iterative method based on two queue, queue<TreeNode*> and queue<int>.
Based on level traversal, queue<int> is used to store the longest consecutive path that ends
at current node.
time complexity: O(n)
space complexity: O(n/2)
 */

#include <iostream>
#include <queue>
using namespace std;

namespace binary_tree_longest_consecutive_sequence {
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root)
            return 0;
        int ans = 1;
        dfs(root, ans);
        return ans;
    }
    int dfs(TreeNode* root, int& ans) {
        if (!root)
            return 0;
        int leftLen = dfs(root->left, ans);
        int rightLen = dfs(root->right, ans);
        int length = 1;
        if (leftLen > 0 && root->val + 1 == root->left->val)
            length = 1 + leftLen;
        if (rightLen > 0 && root->val + 1 == root->right->val && 1 + rightLen > length)
            length = 1 + rightLen;
        if (length > ans)
            ans = length;
        return length;
    }
};

class Solution2 {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root)
            return 0;
        int ans = 1;
        queue<TreeNode*> Q1;
        queue<int> Q2;
        Q1.push(root);
        Q2.push(1);
        while (Q1.size()) {
            TreeNode* cur = Q1.front();
            Q1.pop();
            int count = Q2.front();
            Q2.pop();
            if (cur->left) {
                Q1.push(cur->left);
                if (cur->val + 1 == cur->left->val) {
                    Q2.push(count + 1);
                    if (count + 1 > ans)
                        ans = count + 1;
                } else
                    Q2.push(1);
            }
            if (cur->right) {
                Q1.push(cur->right);
                if (cur->val + 1 == cur->right->val) {
                    Q2.push(count + 1);
                    if (count + 1 > ans)
                        ans = count + 1;
                } else
                    Q2.push(1);
            }
        }
        return ans;
    }
};
}
