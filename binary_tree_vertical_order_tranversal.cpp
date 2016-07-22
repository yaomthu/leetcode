/**
 * Binary tree vertical order tranversal
 * Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,8,4,0,1,7],
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2
return its vertical order traversal as:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]

solution: 先使用dfs求出vertical总共存在多少层，然后使用基于queue的按层序遍历的方式将每个元素放到相应的vertical层
time complexity: O(n)
改进思路：使用hashmap<int,vector<int>>来记录每层的元素，key是level，可以是负数，但在把hashmap里的内容
放入ans时，从最小的key遍历到最大的key。
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace binary_tree_vertical_order_traversal {
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
   vector<vector<int> > verticalOrder(TreeNode* root) {
       if (!root)
           return vector<vector<int> >();
       int leftLen = 0, rightLen = 0;
       dfs(root, leftLen, rightLen, 0);
       vector<vector<int> > ans(rightLen - leftLen + 1, vector<int>());
       queue<pair<TreeNode*, int> > Q;
       Q.push(make_pair(root, -leftLen));
       while (Q.size()) {
           auto cur = Q.front();
           Q.pop();
           ans[cur.second].push_back(cur.first->val);
           if (cur.first->left)
               Q.push(make_pair(cur.first->left, cur.second - 1));
           if (cur.first->right)
               Q.push(make_pair(cur.first->right, cur.second + 1));
       }
       return ans;
   }
   void dfs(TreeNode* root, int& leftLen, int& rightLen, int level) {
       if (level < leftLen)
           leftLen = level;
       if (level > rightLen)
           rightLen = level;
       if (root->left)
           dfs(root->left, leftLen, rightLen, level-1);
       if (root->right)
           dfs(root->right, leftLen, rightLen, level+1);
   }
};
}
