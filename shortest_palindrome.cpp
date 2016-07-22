/**
 * Shortest palindrome
 * Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for additional test cases.

Subscribe to see which companies asked this question

solution: kmp 算法变形, s = s + "#" + reverse(s)，计算next数组
time complexity: O(n)
space complexity: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace shortest_palindrome {
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        string t = s;
        reverse(t.begin(), t.end());
        s = s+"#"+t;
        vector<int> next;
        calNext(next, s);
        s = t;
        reverse(s.begin(), s.end());
        return t.substr(0, t.size()-next.back()) + s;
    }
    void calNext(vector<int>& next, string s) {
        int i = 0, j = -1;
        next.push_back(-1);
        while (i < s.size()) {
            if (j==-1 || s[i] == s[j]) {
                i++;
                j++;
                next.push_back(j);
            } else {
                j = next[j];
            }
        }
    }
};
}

int main_shortest_palindrome() {
  string s = "aacecaaa";
  cout << (new shortest_palindrome::Solution())->shortestPalindrome(s);
}
