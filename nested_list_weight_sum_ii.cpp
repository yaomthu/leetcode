/**
 * Nested list weight sum
 * Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)

Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)

solution: 使用队列来存放某一层的所有节点。每次只处理该层节点，如果某些元素不是数字，则将该元素的所有子元素都
压入队列里。使用levelSum来记录每一层的元素和，prev来记录到当前层为止所有数字的加权和。total为所有元素的加权和
time complexity: O(n)
space complexity:O(n)
 */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace nested_list_weight_sum_ii {
class NestedInteger {
 public:
  bool isInteger() {
    return true;
  }
  int getInteger() {
    return 0;
  }
  vector<NestedInteger>& getList() {
    return data;
  }
 private:
  vector<NestedInteger> data;
};
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        if (nestedList.empty())
            return 0;
        queue<NestedInteger> Q;
        for (auto element : nestedList)
            Q.push(element);
        int total = 0;
        int prev = 0;
        while (Q.size()) {
            int size = Q.size();
            int levelSum = 0;
            for (int i = 0; i < size; i++) {
                NestedInteger cur = Q.front();
                Q.pop();
                if (cur.isInteger())
                    levelSum += cur.getInteger();
                else {
                    for (auto element : cur.getList())
                        Q.push(element);
                }
            }
            prev += levelSum;
            total += prev;
        }
        return total;
    }
};
}
