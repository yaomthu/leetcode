/**
 * Text edit minimum cost
 * Given a list of words and the maximum length of each line, edit the words line by line. There is only one space between two words.
 * The cost of each line is defined as the square of number of space at the end the line. Try to
 * minimize the total cost of all lines.
 *
 * solution: dynamic programing. Use dp[i] to record the minimum total cost for words[0,...,i] and the last line ends with
 * word[i]. dp[i] = min(dp[j-1] + cost(word[j],...,word[i] in the last line))
 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace text_edit_minimum_cost {
class Solution {
 public:
  int minimumCost(vector<string>& words, int length) {
    int n = words.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = square(length - words[0].size());
    for (int i = 1; i < n; i++) {
      int extra = length - words[i].size();
      if (dp[i] > square(extra) + dp[i-1]) {
        dp[i] = square(extra) + dp[i-1];
      }
      for (int j = i - 1; j >= 0 && extra - (int)words[j].size() - 1 >= 0; j--) {
        if (j > 0) {
          if (dp[i] > dp[j-1] + square(extra - words[j].size() - 1)) {
            dp[i] = dp[j-1] + square(extra - words[j].size() - 1);
          }
        } else {
          if (dp[i] > square(extra - words[j].size() - 1)) {
            dp[i] = square(extra - words[j].size() - 1);
          }
        }
        extra -= (words[j].size() + 1);
      }
    }
    return dp[n-1];
  }
  int square(int num) {
    return num * num;
  }
};
}

int main_text_edit_minimum_cost() {
  vector<string> words;
  words.push_back("aaa");
  words.push_back("bb");
  words.push_back("cc");
  words.push_back("ddddd");
  cout << (new text_edit_minimum_cost::Solution())->minimumCost(words, 6);
}
