/**
 * 如果一棵树通过翻转左右子树即可得到另一棵树，则这两棵树相似。例子
 *      1               1
 *    /   \           /   \
 *   2     3         3     2
 *  / \   / \       / \   / \
 * 4   5 6   7     6   7 5   4
 *
 *solution:
 *solution 1: dfs 算法
 *   time complexity: O(n^2)
 *   space complexity: O(n^2)
 *solution 2: 非递归算法，需要使用队列, 但我想的思路要求每个节点值不重复，有问题。
 *   time complexity: O(n)
 *   space complexity: O(n)
 */
#include <iostream>
#include <queue>
using namespace std;

namespace similar_tree_google {
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val_): val(val_), left(NULL), right(NULL) {} 
};

class Solution_dfs {
 public:
  bool isSimilar(TreeNode* r1, TreeNode* r2) {
    if (r1 == NULL && r2 == NULL)
      return true;
    if ((r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL) || r1->val != r2->val)
      return false;
    if ((isSimilar(r1->left, r2->left) && isSimilar(r1->right, r2->right)) ||
        (isSimilar(r1->right, r2->left) && isSimilar(r1->left, r2->right)))
      return true;
    return false;
  }
};
}

int main() {
  similar_tree_google::TreeNode* r1 = new similar_tree_google::TreeNode(1);
  similar_tree_google::TreeNode* r2 = new similar_tree_google::TreeNode(1);
  r1->left = new similar_tree_google::TreeNode(2);
  r1->right = new similar_tree_google::TreeNode(3);
  r1->left->left = new similar_tree_google::TreeNode(4);
  r1->left->right = new similar_tree_google::TreeNode(5);
  r1->right->left = new similar_tree_google::TreeNode(6);
  r1->right->right = new similar_tree_google::TreeNode(7);
  r2->left = new similar_tree_google::TreeNode(3);
  r2->right = new similar_tree_google::TreeNode(2);
  r2->left->left = new similar_tree_google::TreeNode(7);
  r2->left->right = new similar_tree_google::TreeNode(6);
  r2->right->left = new similar_tree_google::TreeNode(5);
  r2->right->right = new similar_tree_google::TreeNode(4);
  if ((new similar_tree_google::Solution_dfs())->isSimilar(r1, r2))
    cout << "true";
  else
    cout << "false";
}
