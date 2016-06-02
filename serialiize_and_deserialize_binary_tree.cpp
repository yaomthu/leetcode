/**
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

namespace serialize_and_deserialize_binary_tree {
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
          return "";
        string text;
        queue<TreeNode*> Q;
        Q.push(root);
        while (Q.size()) {
            TreeNode* cur = Q.front();
            Q.pop();
            if (cur == NULL)
                text += "#,";
            else {
                text += to_string(cur->val) + ",";
                Q.push(cur->left);
                Q.push(cur->right);
            }
        }
        while (text.back() == '#' || text.back() == ',')
          text.pop_back();
        return text;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;
        vector<string> nodes;
        splitString(nodes, data, ',');
        TreeNode* root = new TreeNode(atoi(nodes[0].c_str()));
        queue<TreeNode*> Q;
        Q.push(root);
        int index = 1;
        while (Q.size() && index < nodes.size()) {
            TreeNode* cur = Q.front();
            Q.pop();
            if (nodes[index] != "#") {
                cur->left = new TreeNode(atoi(nodes[index].c_str()));
                Q.push(cur->left);
            }
            index++;
            if (index < nodes.size() && nodes[index] != "#") {
                cur->right = new TreeNode(atoi(nodes[index].c_str()));
                Q.push(cur->right);
            }
            index++;
        }
        return root;
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

int main_serilize_and_deserialize_binary_tree() {
  using namespace serialize_and_deserialize_binary_tree;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);
  string text = (new Codec())->serialize(root);
  cout << text << endl;

}
