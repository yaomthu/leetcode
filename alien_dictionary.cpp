/**
 * Alien Dictionary
 * There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
Show Company Tags
Show Tags
Show Similar Problems
 *
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace alien_dictionary {
class Solution {
public:
    string alienOrder(vector<string>& words) {
        string ans;
        if (words.empty())
            return ans;
        vector<vector<bool> > graph(26, vector<bool>(26, false));
        vector<int> in(26, 0);
        vector<bool> exist(26, false);
        for (int i = 0; i < words.size(); i++) {
            string pre = words[i];
            for (int j = 0; j < pre.size(); j++)
                exist[pre[j]-'a'] = true;
            for (int j = i+1; j < words.size(); j++) {
                string cur = words[j];
                int p1 = 0, p2 = 0;
                while (p1 < pre.size() && p2 < cur.size()) {
                    if (pre[p1] != cur[p2]) {
                        if (graph[pre[p1]-'a'][cur[p2]-'a'] == false) {
                          graph[pre[p1]-'a'][cur[p2]-'a'] = true;
                          in[cur[p2]-'a']++;
                        }
                        break;
                    }
                    p1++;
                    p2++;

                }
            }
        }
        queue<int> Q;
        for (int i = 0; i < 26; i++) {
            if (exist[i] && in[i] == 0)
                Q.push(i);
        }
        while (Q.size()) {
            int cur = Q.front();
            Q.pop();
            char ch = 'a' + cur;
            ans += ch;
            for (int j = 0; j < 26; j++) {
                if (graph[cur][j]) {
                    graph[cur][j] = false;
                    in[j]--;
                    if (in[j] == 0)
                        Q.push(j);
                }
            }
        }
        int total = 0;
        for (int i = 0; i < 26; i++)
            if (exist[i])
                total++;
        return ans.size() == total? ans : "";
    }
};
}

int main_alien_dictionary() {
  vector<string> words;
  words.push_back("wrt");
  words.push_back("wrf");
  words.push_back("er");
  words.push_back("ett");
  words.push_back("rftt");
  cout << (new alien_dictionary::Solution())->alienOrder(words);
}
