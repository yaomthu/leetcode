/**
 * Word pattern ii
 * Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.

Show Company Tags
Show Tags
Show Similar Problems

solution 1: stupid method
solutino 2: optimize based on the two hashmaps.
 *
 */

#include <iostream>
#include <unordered_map>
using namespace std;

namespace word_pattern_ii {
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        if (pattern.empty() ^ str.empty())
            return false;
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        return dfs(pattern, 0, p2s, str, 0, s2p);
    }
    bool dfs(string& pattern, int pstart, unordered_map<char, string>& p2s, string& str, int sstart, unordered_map<string, char>& s2p) {
        if (pstart == pattern.size() || sstart == str.size()) {
            return pstart == pattern.size() && sstart == str.size();
        }
        char ch = pattern[pstart];
        for (int i = sstart; i < str.size(); i++) {
            string temp = str.substr(sstart, i - sstart + 1);
            if (p2s.find(ch) != p2s.end() && s2p.find(temp) != s2p.end()) {
                if (p2s[ch] != temp || s2p[temp] != ch)
                    continue;
                if (dfs(pattern, pstart+1, p2s, str, i+1, s2p))
                    return true;
            } else if (p2s.find(ch) == p2s.end() && s2p.find(temp) == s2p.end()) {
                p2s[ch] = temp;
                s2p[temp] = ch;
                if (dfs(pattern, pstart+1, p2s, str, i+1, s2p))
                    return true;
                p2s.erase(ch);
                s2p.erase(temp);
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool wordPatternMatch(string pattern, string str) {
        if (pattern.empty() ^ str.empty())
            return false;
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        return dfs(pattern, 0, p2s, str, 0, s2p);
    }
    bool dfs(string& pattern, int pstart, unordered_map<char, string>& p2s, string& str, int sstart, unordered_map<string, char>& s2p) {
        if (pstart == pattern.size() || sstart == str.size()) {
            return pstart == pattern.size() && sstart == str.size();
        }
        char ch = pattern[pstart];
        if (p2s.find(ch) != p2s.end()) {
            int len = p2s[ch].size();
            string temp = str.substr(sstart, len);
            if (temp == p2s[ch] && s2p.find(temp) != s2p.end() && s2p[temp] == ch)
                return dfs(pattern, pstart+1, p2s, str, sstart+len, s2p);
            else
                return false;
        } else {
            for (int i = sstart; i < str.size(); i++) {
                string temp = str.substr(sstart, i - sstart + 1);
                if (s2p.find(temp) != s2p.end())
                    continue;
                p2s[ch] = temp;
                s2p[temp] = ch;
                if (dfs(pattern, pstart+1, p2s, str, i+1, s2p))
                    return true;
                p2s.erase(ch);
                s2p.erase(temp);
            }
            return false;
        }
    }
};
}


