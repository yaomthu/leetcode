/**
 * Different Ways to Add Parentheses
 *Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

solution 1: divide and conquer. 遇到'+', '-' or '*' 符号时，分别先求解符号左侧的结果leftS和符号右侧的结果rightS.
如果数组没有符号，则直接计算该数组表示的数值。
time complexity: O(2^n)
space complexity: O(n)

solution 2: 在solution 1 的基础上使用hashmap<string, vector<int>> record来记录中间结果。
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace different_ways_to_add_parentheses {
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        if (input.empty())
            return ans;
        dfs(ans, input, 0, input.size()-1);
        return ans;
    }
    void dfs(vector<int>& ans, string& input, int left, int right) {
        for (int i=left; i<=right; i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> leftS, rightS;
                dfs(leftS, input, left, i-1);
                dfs(rightS, input, i+1, right);
                for (int j=0; j<leftS.size(); j++) {
                    for (int k=0; k<rightS.size(); k++) {
                        ans.push_back(getRet(leftS[j], rightS[k], input[i]));
                    }
                }
            }
        }
        if (ans.empty()) {
            int sum = 0;
            for (int i=left; i<=right; i++) {
                sum = sum*10+input[i]-'0';
            }
            ans.push_back(sum);
        }
    }
    int getRet(int a, int b, char op) {
        switch (op) {
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            default : return 0;
        }
    }
};

class SolutionDP {
 public:
  vector<int> diffWaysToCompute(string input) {
      vector<int> ans;
      if (input.empty())
          return ans;
      unordered_map<string, vector<int> > record;
      return dfs(input, 0, input.size()-1, record);
  }
  vector<int> dfs(string& input, int left, int right, unordered_map<string, vector<int> >& record) {
      if (record.find(input.substr(left, right-left+1)) != record.end())
          return record[input.substr(left, right-left+1)];
      vector<int> ans;
      for (int i=left; i<=right; i++) {
          if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
              vector<int> leftS = dfs(input, left, i-1, record);
              vector<int> rightS = dfs(input, i+1, right, record);
              for (int j=0; j<leftS.size(); j++) {
                  for (int k=0; k<rightS.size(); k++) {
                      ans.push_back(getRet(leftS[j], rightS[k], input[i]));
                  }
              }
          }
      }
      if (ans.empty()) {
          int sum = 0;
          for (int i=left; i<=right; i++) {
              sum = sum*10+input[i]-'0';
          }
          ans.push_back(sum);
      }
      record[input.substr(left, right-left+1)] = ans;
      return ans;
  }
  int getRet(int a, int b, char op) {
      switch (op) {
          case '+': return a+b;
          case '-': return a-b;
          case '*': return a*b;
          default : return 0;
      }
  }
};
}


