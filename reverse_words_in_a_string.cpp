/**
 * Reverse words in a string
 * Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
 */

#include <iostream>
using namespace std;

namespace reverse_words_in_a_string {
class Solution {
public:
    void reverseWords(string &s) {
        revert(s, 0, s.size()-1);
        int start = 0;
        while (start < s.size()) {
            int end = start + 1;
            while (end < s.size() && s[end] != ' ')
                end++;
            revert(s, start, end-1);
            start = end + 1;
        }
    }

    void revert(string&s, int start, int end) {
        while (start < end) {
            char ch = s[start];
            s[start] = s[end];
            s[end] = ch;
            start++;
            end--;
        }
    }
};
}
