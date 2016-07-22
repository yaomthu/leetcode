/**
 * Longest palindromic substring
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
time complexity: similar to O(n).
 *
 */

#include<iostream>
using namespace std;

namespace longest_palindromic_substring {
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        int index = 0, maxLength = 1;
        for (int i = 0; i < s.size();) {
            if (s.size() - i < maxLength/2)
                break;
            int k = i;
            int j = i;
            while (k < s.size()-1 && s[k+1] == s[k])
                k++;
            i = k + 1;
            while (j > 0 && k < s.size()-1 && s[j-1] == s[k+1]) {
                j--;
                k++;
            }
            if (k - j + 1 > maxLength) {
                maxLength = k - j + 1;
                index = j;
            }
        }
        return s.substr(index, maxLength);
    }
};
}
