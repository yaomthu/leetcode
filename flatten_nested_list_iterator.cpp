/**
 * Flatten Nested List Iterator
 * Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

solution: hasNext() 函数判断是否存在数值形式的下一个元素，并把start指向该元素，next() 函数只负责取出start所指向的元素，并对start+1.


 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

namespace flatten_nested_list_iterator {
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

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        start = nestedList.begin();
        end = nestedList.end();
    }

    int next() {
        int ans = start->getInteger();
        start++;
        return ans;
    }

    bool hasNext() {
        while(start != end || r_start.size()) {
            if (start == end) {
                start = r_start.top();
                r_start.pop();
                start++;
                end = r_end.top();
                r_end.pop();
                continue;
            }
            if (start->isInteger())
                return true;
            else {
                r_end.push(end);
                end = start->getList().end();
                r_start.push(start);
                start = start->getList().begin();
            }
        }
        return false;
    }
private:
    stack<vector<NestedInteger>::iterator> r_start;
    stack<vector<NestedInteger>::iterator> r_end;
    vector<NestedInteger>::iterator start, end;
};

class NestedIterator2{
 public:
  NestedIterator2(vector<NestedInteger> &nestedList) {
      for (int i = nestedList.size()-1; i >= 0; i--)
          record.push(nestedList[i]);
  }

  int next() {
      int num = record.top().getInteger();
      record.pop();
      return num;
  }

  bool hasNext() {
      if (record.empty())
          return false;
      while (record.size() && record.top().isInteger() == false) {
          NestedInteger top = record.top();
          record.pop();
          for (int i = top.getList().size()-1; i >= 0; i--) {
              record.push(top.getList()[i]);
          }
      }
      return record.empty()? false : true;
  }
private:
  stack<NestedInteger> record;
};
}
