/**
 * Count of Smaller Numbers After Self
 * You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].

solution:
solution 1: divide and conquer, mergeSort method
time complexity: O(nlogn)
space complexity: O(n)

solution 2: binary index tree. 数组从后往前遍历，建立一棵BST。每个节点记录(val, smalls, count)这三项信息
smalls表示BST里比该节点的值小的节点数，count表示该节点值相同的个数。添加某个元素时，从root节点开始寻找该元素的
最终位置。
注意：smalls表示的是在二叉树里比该节点小的元素个数，而不是在数组里在该元素右边比该元素小的个数。
time complexity: O(nlogn)
space complexity: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace count_of_smaller_numbers_after_self {
class Solution_mergeSort {
struct node {
    int val;
    int index;
    node(int val_, int index_) : val(val_), index(index_) {}
    node& operator = (node& b) {
        val = b.val;
        index = b.index;
        return *this;
    }
};
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return vector<int>();
        vector<int> ans(nums.size(), 0);
        vector<node> datas;
        for (int i=0; i<nums.size(); i++) {
            datas.push_back(node(nums[i], i));
        }
        mergeSort(ans, datas, 0, datas.size()-1);
        return ans;
    }
    void mergeSort(vector<int>& ans, vector<node>& datas, int start, int end) {
        if (start == end)
            return;
        int mid = (start+end)/2;
        mergeSort(ans, datas, start, mid);
        mergeSort(ans, datas, mid+1, end);
        vector<node> temp(end-start+1, node(0, 0));
        int i = mid, j = end, index = end-start;
        while (i >= start && j >= mid+1) {
            if (datas[i].val <= datas[j].val) {
                temp[index--] = datas[j--];
            } else {
                ans[datas[i].index] += j-mid;
                temp[index--] = datas[i--];
            }
        }
        while (i >= start)
            temp[index--] = datas[i--];
        while (j >= mid+1)
            temp[index--] = datas[j--];
        for (i = start, index = 0; i <= end; i++, index++)
            datas[i] = temp[index];
    }
};

class Solution_binary_index_tree {
public:
    struct TreeNode
    {
        int val, smalls, count;
        TreeNode *left, *right;
        TreeNode(int val_): val(val_), smalls(0), count(1), left(NULL), right(NULL) {}
    };
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return vector<int>();
        vector<int> ans(nums.size(), 0);
        TreeNode* root = NULL;
        for (int i=ans.size()-1; i>=0; i--) {
            int total = 0;
            if (!root) {
                root = new TreeNode(nums[i]);
            } else {
                TreeNode* cur = root;
                TreeNode* pre = NULL;
                while (cur!=NULL && cur->val!=nums[i]) {
                    pre = cur;
                    if (nums[i] < cur->val) {
                        cur->smalls++;
                        cur = cur->left;
                    } else {
                        total += cur->smalls + cur->count;
                        cur = cur->right;
                    }
                }
                if (!cur) {
                    if (nums[i] > pre->val)
                        pre->right = new TreeNode(nums[i]);
                    else
                        pre->left = new TreeNode(nums[i]);
                } else {
                    cur->count++;
                    total += cur->smalls;
                }
            }
            ans[i] = total;
        }
        return ans;
    }
};
}

int main_count_of_smaller_numbers_after_self() {
  int data[] = {5,2,6,1,0,-1,2};
  vector<int> nums(data, data+7);
  vector<int> ans = (new count_of_smaller_numbers_after_self::Solution_binary_index_tree())->countSmaller(nums);
  for (auto num : ans)
    cout << num <<  " ";
  cout << endl;
}
