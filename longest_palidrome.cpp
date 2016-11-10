/**
 * Longest palidrome
 * Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
 *
 */

#include <iostream>
#include <unordered_map>
using namespace std;
namespace longest_palidrome {
class Solution {
public:
    int longestPalindrome(string s) {
        if (s.empty()) {
            return 0;
        }
        unordered_map<char, int> record;
        for (int i = 0; i < s.size(); i++) {
            record[s[i]]++;
        }
        bool oddCase = false;
        int ans = 0;
        for(auto iter = record.begin(); iter != record.end(); iter++) {
            ans += iter->second / 2 * 2;
            if ((iter->second & 1) == 1) {
                oddCase = true;
            }
        }
        return oddCase? ans + 1 : ans;
    }
};
}
