/**
 * Word break ii
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

namespace word_break_ii {
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ans;
        if (s.empty() || wordDict.empty())
            return ans;
        int small = INT_MAX, big = 0;
        for (auto word : wordDict) {
            if (word.size() < small)
                small = word.size();
            if (word.size() > big)
                big = word.size();
        }
        vector<bool> flag(s.size()+1, false);
        flag[s.size()] = true;
        for (int i = s.size()-1; i>=0; i--) {
            for (int len = small; len <= big && i + len <= s.size(); len++) {
                if (flag[i+len] && wordDict.find(s.substr(i, len)) != wordDict.end()) {
                    flag[i] = true;
                    break;
                }
            }
        }
        if (flag[0] == false)
            return ans;
        dfs(s, wordDict, 0, "", ans, flag, small, big);
        return ans;
    }
    void dfs(string& s, unordered_set<string>& wordDict, int start, string record, vector<string>& ans, vector<bool>& flag, int small, int big) {
        if (start == s.size()) {
            ans.push_back(record);
            return;
        }
        int size = record.size();
        for (int len = small; len <= big && start + len <= s.size(); len++) {
            if (flag[start+len] && wordDict.find(s.substr(start, len)) != wordDict.end()) {
                if (record.size())
                    record += " ";
                record += s.substr(start, len);
                dfs(s, wordDict, start+len, record, ans, flag, small, big);
                record.resize(size);
            }
        }
    }
};
}

int main_word_break_ii() {
  string s = "catsanddog";
  unordered_set<string> wordDict;
  wordDict.insert("cat");
  wordDict.insert("cats");
  wordDict.insert("and");
  wordDict.insert("sand");
  wordDict.insert("dog");
  vector<string> ans = (new word_break_ii::Solution())->wordBreak(s, wordDict);
  for (auto word : ans)
    cout << word << endl;
}
