/**
 * Nested List Weight Sum
 * solution 1: 递归解法
 * solution 2: 非递归解法，使用两个栈，一个栈存放该层所访问的地址，另一个栈存放该层的结束位置。
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

namespace nested_list_weight_sum {
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

class Solution_recursive {
 public:
  int depthSum(vector<NestedInteger>& nestedList) {
    return dfs(nestedList, 1);
  }
  int dfs(vector<NestedInteger>& nestedList, int level) {
    int ans = 0;
    for (int i=0; i<nestedList.size(); i++) {
      if (nestedList[i].isInteger())
        ans += nestedList[i].getInteger() * level;
      else
        ans += dfs(nestedList[i].getList(), level+1);
    }
    return ans;
  }
};

class Solution_iterate {
 public:
  int depthSum(vector<NestedInteger>& nestedList) {
    int ans = 0;
    int level = 1;
    stack<vector<NestedInteger>::iterator> r_start;
    stack<vector<NestedInteger>::iterator> r_end;
    vector<NestedInteger>::iterator start = nestedList.begin();
    vector<NestedInteger>::iterator end = nestedList.end();
    while (start != end || r_start.size()) {
      if (start == end) {
        start = r_start.top();
        r_start.pop();
        end = r_end.top();
        r_end.pop();
        start++;
        level--;
        continue;
      }
      if (start->isInteger()) {
        ans += start->getInteger() * level;
        start++;
      } else {
        r_end.push(end);
        end = start->getList().end();
        r_start.push(start);
        start = start->getList().begin();
        level++;
      }
    }
    return ans;
  }
};
}
