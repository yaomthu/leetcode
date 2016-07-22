/**
 * Substring with concatenation of all words
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

Subscribe to see which companies asked this question

solution: 前后index解法，遍历起始位置[0, len-1]。
time complexity: O(word[0].lenth * S.length)
space complexity: O(words.size()).

notes: 记得先判断temp是否在hashmap record里
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace substring_with_concatenation_of_all_words {
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.size() < words.size() * words[0].size())
            return ans;
        unordered_map<string, int> record;
        for (auto word : words)
            record[word]++;
        unordered_map<string, int> window;
        int len = words[0].size();
        int length = words.size() * len;

        for (int start = 0; start < len; start++) {
            int count = record.size();
            window.clear();
            int left = start;
            int right = start;
            while (right - left < length) {
                string temp = s.substr(right, len);
                window[temp]++;
                if (record.find(temp) != record.end() && window[temp] == record[temp])
                    count--;
                right += len;
            }
            if (count == 0)
                ans.push_back(left);
            while (right < s.size()) {
                string temp = s.substr(left, len);
                left += len;
                window[temp]--;
                if (record.find(temp) != record.end() && window[temp] < record[temp])
                    count++;
                temp = s.substr(right, len);
                right += len;
                window[temp]++;
                if (record.find(temp) != record.end() && window[temp] == record[temp])
                    count--;
                if (count == 0)
                    ans.push_back(left);
            }
        }
        return ans;
    }
};
}

int main_substring_with_concatenation_of_all_words() {
  string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
  vector<string> words;
  words.push_back("fooo");
  words.push_back("barr");
  words.push_back("wing");
  words.push_back("ding");
  words.push_back("wing");
  vector<int> ans = (new substring_with_concatenation_of_all_words::Solution())->findSubstring(s, words);
  for (auto index : ans)
      cout << index << " ";
}
