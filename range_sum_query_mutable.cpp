/**
 * Range sum query mutable
 *Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
 *
 *solution: 线段树来解决该题，树的每个节点存放三个域: 数组下标start, 数组下标end, 和数组[start, end]之间的和sum。
 * update时，不需要使用dfs，直接找出从root到符合条件的叶子节点的路径，更新这条路径上的节点的sum
 * query时，使用dfs方法进行求解。
 *time complexity of update and query is: O(logn)
 *space complexity is O(n)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

namespace range_sum_query_mutable {
class NumArray {
struct TreeNode {
  int start, end, sum;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int start_, int end_, int sum_) : start(start_), end(end_), sum(sum_) {}
};
public:
    NumArray(vector<int> &nums) {
        if (nums.empty())
            root = NULL;
        else
            root = genTree(nums, 0, nums.size()-1);
    }

    void update(int i, int val) {
        vector<TreeNode*> record;
        TreeNode* cur = root;
        while (cur->start != i || cur->end != i) {
            record.push_back(cur);
            if (i <= (cur->start + cur->end)/2)
                cur = cur->left;
            else
                cur = cur->right;
        }
        for (int j=0; j<record.size(); j++)
            record[j]->sum += val-cur->sum;
        cur->sum = val;
    }

    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }

    int sumRange(TreeNode* root, int start, int end) {
        if (start == root->start && end == root->end)
            return root->sum;
        int mid = (root->start+root->end)/2;
        if (start > mid)
            return sumRange(root->right, start, end);
        else if (end <= mid)
            return sumRange(root->left, start, end);
        else
            return sumRange(root->left, start, mid) + sumRange(root->right, mid+1, end);
    }

    TreeNode* genTree(vector<int>& nums, int start, int end) {
        if (start == end)
            return new TreeNode(start, end, nums[start]);
        int mid = (start + end)/2;
        TreeNode* leftChild = genTree(nums, start, mid);
        TreeNode* rightChild = genTree(nums, mid+1, end);
        TreeNode* root = new TreeNode(start, end, leftChild->sum + rightChild->sum);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }
private:
    TreeNode *root;
};
}

int main_range_sum_query_mutable() {
  using namespace range_sum_query_mutable;
  int data[] = {1,3,5};
  vector<int> nums(data, data+3);
  NumArray numArray(nums);
  cout << numArray.sumRange(0,2) << endl;
  numArray.update(1,2);
  cout << numArray.sumRange(0,2) << endl;
}
