/**
 * Binary tree path
 * Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

solution 1: dfs解法，记住dfs判断返回条件是该节点是叶子节点。
time complexity : O(n)
space complexity : O(log n)
solution 2: iterative 方法，使用两个stack，一个stack记录节点信息，一个stack记录path信息。
time complexity : O(n)
space complexity: O(n)
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

namespace binary_tree_path {

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root)
            return ans;
        dfs(ans, root, "");
        return ans;
    }
    void dfs(vector<string>& ans, TreeNode* root, string record) {
        if (record.size())
            record += "->";
        record += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(record);
            return;
        }
        if (root->left)
            dfs(ans, root->left, record);
        if (root->right)
            dfs(ans, root->right, record);
    }
};

class Solution_iterative {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root)
            return ans;
        stack<TreeNode*> nodes;
        stack<string> paths;
        nodes.push(root);
        paths.push(to_string(root->val));
        while (nodes.size()) {
            TreeNode* cur = nodes.top();
            nodes.pop();
            string tmpPath = paths.top();
            paths.pop();
            if (cur->left == NULL && cur->right == NULL)
                ans.push_back(tmpPath);
            else {
                if (cur->left) {
                    nodes.push(cur->left);
                    paths.push(tmpPath + "->" + to_string(cur->left->val));
                }
                if (cur->right) {
                    nodes.push(cur->right);
                    paths.push(tmpPath + "->" + to_string(cur->right->val));
                }
            }
        }
        return ans;
    }
};
}

