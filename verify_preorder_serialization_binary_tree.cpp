/**
 * Verify Preorder Serialization of a Binary Tree
 * One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Solution: 一棵完全二叉树所有节点的出度之和和入度之和相等，且在建树过程中，没遇到一个节点就入度-1，如果该节点是数值节点
则将出度+2.定义 diff = 出度-入度，则遍历preorder数组时，diff值不可能小于0，遍历结束后diff 必然等于0.
time complexity: O(n)
space complexity: O(1)

sub_question_1 : Verify inorder serialization of a binary tree
solution: inorder里的顺序肯定是 #,4,#,3,#,1,#,9,#,2,#,6,#，所以可以初始化diff=1，遇到'#'就减1，遇到非‘#’就加1.
遍历过程中 diff 一直大于等于0，最后等于0.

sub_question_2 : Verify postorder serialization of a binary tree
solution: 初始化diff=1，遇到'#'就减1，遇到非'#'就加1.遍历过程中diff一直小雨等0，最后等于0.
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace verify_preorder_serialization_binary_tree {
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty())
            return true;
        vector<string> nodes;
        splitString(nodes, preorder, ',');
        int diff = 1;
        for (int i=0; i<nodes.size(); i++) {
            diff--;
            if (diff < 0)
                return false;
            if (nodes[i] != "#")
                diff += 2;
        }
        return diff == 0;
    }
    void splitString(vector<string>& nodes, string& s, char delimeter) {
        int start = 0, end = 0;
        while (start < s.size()) {
            end = start + 1;
            while (end < s.size() && s[end] != delimeter)
                end++;
            nodes.push_back(s.substr(start, end-start));
            start = end+1;
        }
    }
};
}

namespace verify_inorder_serialization_binary_tree {
class Solution {
 public:
  bool isValidSerialization(string inorder) {
    if (inorder.empty())
      return true;
    vector<string> nodes;
    splitString(nodes, inorder, ',');
    int diff = 1;
    for (int i=0; i<nodes.size(); i++) {
      if (nodes[i] == "#")
        diff--;
      else
        diff++;
      if (diff < 0)
        return false;
    }
    return diff == 0;
  }
  void splitString(vector<string>& nodes, string& s, char delimeter) {
      int start = 0, end = 0;
      while (start < s.size()) {
          end = start + 1;
          while (end < s.size() && s[end] != delimeter)
              end++;
          nodes.push_back(s.substr(start, end-start));
          start = end+1;
      }
  }
};
}

namespace verify_postorder_serialization_binary_tree {
class Solution {
 public:
  bool isValidSerialization(string postorder) {
    if (postorder.empty())
      return true;
    vector<string> nodes;
    splitString(nodes, postorder, ',');
    int diff = 1;
    for (int i=0; i<nodes.size(); i++) {
      if (nodes[i] == "#")
        diff--;
      else
        diff++;
      if (diff > 0)
         return false;
    }
    return diff == 0;
  }
  void splitString(vector<string>& nodes, string& s, char delimeter) {
      int start = 0, end = 0;
      while (start < s.size()) {
          end = start + 1;
          while (end < s.size() && s[end] != delimeter)
              end++;
          nodes.push_back(s.substr(start, end-start));
          start = end+1;
      }
  }
};
}
int main_verify_preorder_serialization_binary_tree() {
  string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
  if ((new verify_preorder_serialization_binary_tree::Solution())->isValidSerialization(preorder)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  string inorder = "#,3,#,9,#,4,#";
  if ((new verify_inorder_serialization_binary_tree::Solution())->isValidSerialization(inorder)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  string postorder = "#,#,3,#,#,4,9";
  if ((new verify_postorder_serialization_binary_tree::Solution())->isValidSerialization(postorder)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}
