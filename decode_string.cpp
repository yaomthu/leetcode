/**
 * Decode string
 * Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
Subscribe to see which companies asked this question
 */

#include <iostream>
using namespace std;

namespace decode_string {
class Solution {
public:
    string decodeString(string s) {
        if (s.empty()) {
            return s;
        }
        return dfs(s, 0, s.size()-1);
    }
    string dfs(string& s, int start, int end) {
        string res;
        int index = start;
        while (index <= end) {
            if (s[index] >= '0' && s[index] <= '9') {
                int num = 0;
                while (index <= end && s[index] != '[') {
                    num = num * 10 + s[index] - '0';
                    index++;
                }
                int record = 1;
                index++;
                int deepStart = index;
                while (record > 0 && index <= end) {
                    if (s[index] == '[') {
                        record++;
                    } else if (s[index] == ']') {
                        record--;
                    }
                    index++;
                }
                string deapString = dfs(s, deepStart, index - 2);
                for (int i = 0; i < num; i++) {
                    res += deapString;
                }
            } else {
                res += s[index];
                index++;
            }
        }
        return res;
    }
};
}
