/**
 * Is subsequence
 * Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
 */

#include <iostream>
using namespace std;

namespace is_subsequence {
class SimpleSolution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }
        int i = 0, j = 0;
        while (i < s.size()) {
            while (j < t.size() && t[j] != s[i]) {
                j++;
            }
            if (j == t.size()) {
                break;
            }
            j++;
            i++;
        }
        return i == s.size();
    }
};

class BinarySolution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }
        unordered_map<char, vector<int>> record;
        for (int i = 0; i < t.size(); i++) {
            record[t[i]].push_back(i);
        }
        int i = 0;
        int pos = -1;
        for (; i < s.size(); i++) {
            if (record.find(s[i]) == record.end()) {
                break;
            }
            pos = binarySearch(record[s[i]], pos);
            if (pos == -1) {
                break;
            }
        }
        return i == s.size();
    }
    int binarySearch(vector<int>& data, int pos) {
        int left = 0, right = data.size()-1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right)/2;
            if (data[mid] > pos) {
                ans = data[mid];
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
}
