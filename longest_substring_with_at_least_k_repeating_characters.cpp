/**
 * Longest Substring with At Least K Repeating Characters
 * Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
Subscribe to see which companies asked this question

solution: divide and conquer. find some character whose count is less than k, divide at that place.
 */

#include <iostream>
#include <vector>
using namespace std;
namespace longest_substring_with_at_least_k_repeating_characters {
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty()) {
            return 0;
        }
        return dfs(s, 0, s.size()-1, k);
    }
    int dfs(string& s, int start, int end, int k) {
        if (end < start || end - start + 1 < k) {
            return 0;
        }
        vector<int> count(26, 0);
        for (int i = start; i <= end; i++) {
            count[s[i]-'a']++;
        }
        for (int i = start; i <= end; i++) {
            if (count[s[i]-'a'] < k) {
                return maxi(dfs(s, start, i-1, k), dfs(s, i+1, end, k));
            }
        }
        return end-start+1;
    }
    int maxi(int a, int b) {
        return a < b? b : a;
    }
};
}
