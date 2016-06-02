/**
 * Remove invalid parentheses
 *Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
Credits:
Special thanks to @hpplayer for adding this problem and creating all test cases.

solution: 使用left记录'('比')'多的个数，right记录')'比'('多的个数。pair记录未配对的‘(’个数。使用dfs方法进行求解
time complexity: O(2^n)
space complexity:O(2^n)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

namespace remove_invalid_parentheses {
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        if (s.empty()) {
            ans.push_back("");
            return ans;
        }
        int left = 0, right = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(')
                left++;
            else if (s[i] == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }
        unordered_set<string> sets;
        dfs(sets, s, 0, "", left, right, 0);
        for (auto ss : sets)
            ans.push_back(ss);
        return ans;
    }
    void dfs(unordered_set<string>& sets, string& s, int index, string record, int left, int right, int pair) {
        if (index == s.size() && left == 0 && right == 0 && pair == 0) {
            sets.insert(record);
            return;
        }
        if (index == s.size())
            return;
        if (s[index] == '(') {
            if (left > 0)
                dfs(sets, s, index+1, record, left-1, right, pair);
            dfs(sets, s, index+1, record+'(', left, right, pair+1);
        } else if (s[index] == ')') {
            if (pair > 0)
                dfs(sets, s, index+1, record+')', left, right, pair-1);
            dfs(sets, s, index+1, record, left, right-1, pair);
        } else {
            dfs(sets, s, index+1, record+s[index], left, right, pair);
        }
    }
};
}

int main_remove_invalid_parentheses() {
  string s = "(a)())()";
  vector<string> ans = (new remove_invalid_parentheses::Solution())->removeInvalidParentheses(s);
  for (auto ss : ans)
    cout << ss << " ";
}
