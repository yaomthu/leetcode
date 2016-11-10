/**
 * Remove parentheses
 * Given a string with '(' and ')', remove some parentheses to make the string valid.
 */

#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

namespace remove_parentheses {
class Solution {
 public:
  string validParentheses(string s) {
    if (s.empty()) {
      return s;
    }
    stack<pair<char,int> > record;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ')' && record.size() && record.top().first == '(') {
        record.pop();
      } else {
        record.push(make_pair(s[i], i));
      }
    }
    unordered_set<int> indexs;
    while (record.size()) {
      indexs.insert(record.top().second);
      record.pop();
    }
    string ans;
    for (int i = 0; i < s.size(); i++) {
      if (indexs.find(i) != indexs.end()) {
        continue;
      }
      ans += s[i];
    }
    return ans;
  }
};
}

int main_remove_parentheses() {
  string s = "()))))()()";
  cout << (new remove_parentheses::Solution())->validParentheses(s);
}
