/**
 * Minimum changes to be palindrome (snapchat)
 * Given a string, you can change/delete/add some character to  make the string be palindrome.
 * Return the minimum changes needed.
 * solution: dp method, dp[i][i+len-1] = dp[i+1][i+len-2] (if s[i] == s[i+len-1])
 * dp[i][i+len-1] = 1 + min{dp[i+1][i+len-2], dp[i][i+len-2], dp[i+1][i+len-1]}. if (s[i] != s[i+len-1])
 */

#include <iostream>
#include <vector>
using namespace std;

namespace minimum_changes_to_be_palindrome {
class Solution {
public:
  int minimumPalidrome(string s) {
    if (s.size() <= 1)
      return 0;
    vector<vector<int> > dp(s.size(), vector<int>(s.size(), 0));
    for (int i = 0; i<s.size()-1; i++) {
      dp[i][i+1] = s[i]==s[i+1]? 0 : 1;
    }
    for (int len = 3; len <= s.size(); len++) {
      for (int i = 0; i+len <= s.size(); i++) {
        if (s[i] == s[i+len-1])
            dp[i][i+len-1] = dp[i+1][i+len-2];
        else {
            dp[i][i+len-1] = 1 + minThree(dp[i+1][i+len-2], dp[i][i+len-2], dp[i+1][i+len-1]);
        }
      }
    }
    return dp[0][s.size()-1];
  }

  int minThree(int a ,int b, int c) {
    int ans = INT_MAX;
    if (a < ans)
        ans = a;
    if (b < ans)
        ans = b;
    if (c < ans)
        ans = c;
    return ans;
  }
};
}

int main_minimum_changes_to_be_palindrome() {
  string s = "abcd";
  cout << (new minimum_changes_to_be_palindrome::Solution())->minimumPalidrome(s);
}
