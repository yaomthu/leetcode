/**
 * Remove Duplicate Letters
 * Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

solution: 先统计每种字符的出现个数。从头开始遍历字符串，当该字符还没在栈里出现时，若该字符比栈顶字符小且后面字符串里
还有栈顶字符，则出栈，最终将该字符入栈。
注意：如果字符已经在栈里就不做上述操作，因为该字符在栈里已经是处于当前最优的位置。
time complexity: O(n)
space complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace remove_duplicate_letters {
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty())
            return "";
        vector<int> counter(26, 0);
        for (int i=0; i<s.size(); i++)
            counter[s[i]-'a']++;
        string ans;
        int index = 0;
        vector<bool> maps(26, false);
        while (index < s.size()) {
            if (maps[s[index]-'a'] == false) {
                while (ans.size() && s[index] < ans.back() && counter[ans.back()-'a'] > 0) {
                    maps[ans.back()-'a'] = false;
                    ans.pop_back();
                }
                maps[s[index]-'a'] = true;
                ans += s[index];
            }
            counter[s[index]-'a']--;
            index++;
        }
        return ans;
    }
};
}

int main_remove_duplicate_letters() {
  string s = "bcabc";
  cout << (new remove_duplicate_letters::Solution())->removeDuplicateLetters(s);
}
