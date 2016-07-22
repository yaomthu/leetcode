/**
 * Generalized abbreviation
 * Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

 */

#include <iostream>
#include <vector>
using namespace std;

namespace generalized_abbreviation {
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        if (word.empty()) {
            ans.push_back("");
            return ans;
        }
        dfs(word, 0, ans, "", true);
        return ans;
    }
    void dfs(string& word, int start, vector<string>& ans, string record, bool abbr) {
        if (start == word.size()) {
            ans.push_back(record);
            return;
        }
        dfs(word, start+1, ans, record + word[start], true);
        if (abbr) {
            for (int i = start; i < word.size(); i++) {
                dfs(word, i+1, ans, record + to_string(i-start+1), false);
            }
        }
    }
};
}
