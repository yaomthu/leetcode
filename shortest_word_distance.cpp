/**
 * Shortest word distance
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
time complexity : (n)
space complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace shortest_word_distance {
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int ans = INT_MAX;
        string record;
        int index = -1;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1 || words[i] == word2) {
                if (record.empty() || words[i] == record) {
                    index = i;
                } else {
                    if (i - index < ans)
                        ans = i - index;
                    index = i;
                }
                record = words[i];
            }
        }
        return ans;
    }
};
}
