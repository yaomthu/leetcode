/**
 * Group shifted strings
 * Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
A solution is:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
Show Company Tags
Show Tags
Show Similar Problems
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace group_shifted_strings {
class Solution {
public:
    vector<vector<string> > groupStrings(vector<string>& strings) {
        vector<vector<string> > ans;
        if (strings.empty())
            return ans;
        unordered_map<string, vector<string> > record;
        for (auto word : strings) {
            if (word.empty())
                record[""].push_back("");
            else {
                int diff = word[0] - 'a';
                string temp;
                for (int j = 0; j < word.size(); j++) {
                    if (word[j] - 'a' < diff)
                        temp += (char)(word[j] - diff + 26);
                    else
                        temp += (char)(word[j] - diff);
                }
                record[temp].push_back(word);
            }
        }
        for (auto iter = record.begin(); iter != record.end(); iter++)
            ans.push_back(iter->second);
        return ans;
    }
};
}
