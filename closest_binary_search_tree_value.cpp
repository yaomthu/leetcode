/**
 * Closest binary search tree value
 * Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Show Company Tags
Show Tags
Show Similar Problems
 *
 */

#include <iostream>
#include <cmath>
using namespace std;


namespace closest_binary_search_tree_value {
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        while (root) {
            if (abs(root->val - target) < abs(ans - target))
                ans = root->val;
            if (root->val <= target)
                root = root->right;
            else
                root = root->left;
        }
        return ans;
    }
};
}
