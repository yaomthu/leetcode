/**
 * Strobogrammatic number iii
 *A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.
 */

#include <iostream>
using namespace std;

namespace strobogrammatic_number_iii {
class Solution {
 public:
  int strobogrammaticInRange(string lower, string upper) {
    if (upper.size() < lower.size() || (lower.size() == upper.size() && lower > upper))
        return 0;
    string choice = "01689";
    string mid;
    if (lower.size() == upper.size()) {
      int ans = 0;
      mid = lower.size()%2 == 0? "" : "018";
      dfs(ans, 0, "", choice, mid, lower, upper);
      return ans;
    } else {
      int part1 = 0;
      mid = lower.size()%2 == 0? "": "018";
      dfs(part1, 0, "", choice, mid, lower, string(lower.size(), '9'));
      int part3 = 0;
      mid = upper.size()%2 == 0? "": "018";
      dfs(part3, 0, "", choice, mid, '1' + string(upper.size()-1, '0'), upper);
      int part2 = 0;
      for (int n = lower.size() + 1; n < upper.size(); n++) {
        int temp = 1;
        for (int i = 0; i < n/2; i++) {
          if (i == 0)
              temp *= 4;
          else
              temp *= 5;
        }
        if (n%2 == 1)
            temp *= 3;
        part2 += temp;
      }
      return part1 + part2 + part3;
    }
  }

  void dfs(int& ans, int start, string left, string& choice, string& mid, string lower, string upper) {
    int n = lower.size();
    if (start == n/2) {
      string right = convert(left);
      if (n%2 == 1) {
        for (int i = 0; i < mid.size(); i++) {
          if (valid(left + mid[i] + right, lower, upper))
            ans++;
        }
      } else {
        if (valid(left + right, lower, upper))
            ans++;
      }
      return;
    }
    int size = left.size();
    for (int i = 0; i < choice.size(); i++) {
      if (i == 0 && left.empty())
        continue;
      left += choice[i];
      dfs(ans, start+1, left, choice, mid, lower, upper);
      left.resize(size);
    }
  }

  string convert(string& left) {
    string right;
    if (left.empty())
      return right;
    for (int i = left.size()-1; i >= 0; i--) {
      if (left[i] == '0' || left[i] == '1' || left[i] == '8')
        right += left[i];
      else
        right += left[i] == '6'? '9' : '6';
    }
    return right;
  }

  bool valid(string res, string lower, string upper) {
    return res >= lower && res <= upper;
  }
};
}

int main_strobogrammatic_number_iii() {
  cout << (new strobogrammatic_number_iii::Solution())->strobogrammaticInRange("0", "99");
}
