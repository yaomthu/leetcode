/**
 * Cloest binary search tree value ii
 * Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

Show Hint
Show Company Tags
Show Tags
Show Similar Problems

solution: use bst property, visit the bst from root to leaf, push the node with value > target into stack succ,
push the node with value <= target into stack pred. Functin getSucc(succ) and getPred(pred) are very important.
 *
 */

#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

namespace cloest_binary_search_value_ii {
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        stack<TreeNode*> pred, succ;
        TreeNode* cur = root;
        while (cur) {
            if (cur->val <= target) {
                pred.push(cur);
                cur = cur->right;
            } else {
                succ.push(cur);
                cur = cur->left;
            }
        }
        while (k) {
            if (pred.empty() && succ.empty())
                break;
            else if (succ.empty()) {
                ans.push_back(getPred(pred));
            } else if (pred.empty()) {
                ans.push_back(getSucc(succ));
            } else {
                if (abs(pred.top()->val - target) < abs(succ.top()->val - target))
                    ans.push_back(getPred(pred));
                else
                    ans.push_back(getSucc(succ));
            }
            k--;
        }
        return ans;
    }
    int getPred(stack<TreeNode*>& pred) {
        TreeNode* cur = pred.top();
        pred.pop();
        int result = cur->val;
        cur = cur->left;
        while (cur) {
            pred.push(cur);
            cur = cur->right;
        }
        return result;
    }
    int getSucc(stack<TreeNode*>& succ) {
        TreeNode* cur = succ.top();
        succ.pop();
        int result = cur->val;
        cur = cur->right;
        while (cur) {
            succ.push(cur);
            cur = cur->left;
        }
        return result;
    }
};
}
