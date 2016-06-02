/**
 * Word pattern
 * Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

Credits:
Special thanks to @minglotus6 for adding this problem and creating all test cases.
solution: 使用两个hashmap，一个是hashmap<char, string>，另一个是hashmap<string,char>
time complexity: O(n)
space complexity: O(n)
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace word_pattern {
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        splitString(words, str);
        if (pattern.size() != words.size())
            return false;
        unordered_map<char, string> record1;
        unordered_map<string, char> record2;
        for (int i=0; i<pattern.size(); i++) {
            if (record1.find(pattern[i]) == record1.end() && record2.find(words[i]) != record2.end())
                return false;
            else if (record1.find(pattern[i]) != record1.end() && record2.find(words[i]) == record2.end())
                return false;
            else if (record1.find(pattern[i]) == record1.end() && record2.find(words[i]) == record2.end()) {
                record1[pattern[i]] = words[i];
                record2[words[i]] = pattern[i];
            } else {
                if (record1[pattern[i]] != words[i] || record2[words[i]] != pattern[i])
                    return false;
            }
        }
        return true;
    }
    void splitString(vector<string>& words, string& s) {
        int start = 0;
        while (start < s.size()) {
            int end = start;
            while (end<s.size() && s[end]!=' ')
                end++;
            words.push_back(s.substr(start, end-start));
            start = end+1;
        }
    }
};
}

int main_word_pattern() {
  string pattern = "abba";
  string str = "dog cat cat dog";
  if ((new word_pattern::Solution())->wordPattern(pattern, str))
    cout << "true";
  else
    cout << "false";
}
