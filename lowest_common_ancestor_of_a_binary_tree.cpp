/**
 * Lowest common ancestor of a binary tree
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Solution 1: recursive method.

Solution 2: iterative method.使用hashmap<TreeNode*, TreeNode*> parents来记录每个节点的父节点，然后遍历整棵树，直到
p和q的父节点信息都记录到parents表里。

Subscribe to see which companies asked this question
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

namespace lowest_common_ancestor_of_a_binary_tree {

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_recursive {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        vector<TreeNode*> pathP, pathQ;
        dfs(root, pathP, p);
        dfs(root, pathQ, q);
        int index = 0;
        while (index < pathP.size() && index < pathQ.size() && pathP[index] == pathQ[index])
            index++;
        return pathP[index-1];
    }
    bool dfs(TreeNode* root, vector<TreeNode*>& path, TreeNode* target) {
        if (root == target) {
            path.push_back(root);
            return true;
        }
        if (root->left) {
            path.push_back(root);
            if (dfs(root->left, path, target))
                return true;
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root);
            if (dfs(root->right, path, target))
                return true;
            path.pop_back();
        }
        return false;
    }
};

class Solution_iterative {
 public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (!root)
             return NULL;
         unordered_map<TreeNode*, TreeNode*> parents;
         parents[root] = NULL;
         queue<TreeNode*> Q;
         Q.push(root);
         while (parents.find(p) == parents.end() || parents.find(q) == parents.end()) {
             TreeNode* cur = Q.front();
             Q.pop();
             if (cur->left) {
                 Q.push(cur->left);
                 parents[cur->left] = cur;
             }
             if (cur->right) {
                 Q.push(cur->right);
                 parents[cur->right] = cur;
             }
         }
         unordered_set<TreeNode*> pathP;
         while (p != NULL) {
             pathP.insert(p);
             p = parents[p];
         }
         while (pathP.find(q) == pathP.end()) {
             q = parents[q];
         }
         return q;
     }
};
}
