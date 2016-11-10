/**
 * Longest Substring with At Most Two Distinct Characters  QuestionEditorial Solution  My Submissions
Total Accepted: 13939
Total Submissions: 38555
Difficulty: Hard
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
 */

#include <iostream>
#include <vector>
using namespace std;

namespace longest_substring_with_at_most_two_distinct_characters {
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty())
            return 0;
        int start = 0;
        int end = 0;
        vector<int> cmap(256, 0);
        int count = 0;
        int ans = 0;
        while (end < s.size()) {
            while (end < s.size()) {
                if (cmap[s[end]] == 0)
                    count++;
                cmap[s[end]]++;
                if (count > 2)
                    break;
                end++;
            }
            if (end - start > ans)
                ans = end - start;
            while (start < end && count > 2) {
                cmap[s[start]]--;
                if (cmap[s[start]] == 0)
                    count--;
                start++;
            }
            end++;
        }
        return ans;
    }
};
}
