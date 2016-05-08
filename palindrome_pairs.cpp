/**
 * Palindrome Pairs
 *Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

solution: 先使用hashmap记录每个单词的位置，针对每个单词，(left | palindrome) right 和 left (palindrome | right)的情况。
记得先考虑palindrome长度为 0 和 长度为单词长度的情况。
time complexity : O(n*k^2), k是平均单词长度
space complexity: O(n)
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

namespace palindrome_pairs {
class Solution {
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > ans;
        if(words.empty())
            return ans;
        unordered_map<string, int> stringMap;
        for(int i=0; i<words.size(); i++) {
            stringMap[words[i]] = i;
        }
        for(int i=0; i<words.size(); i++) {
            if (words[i].size() && isPalindrome(words[i]) && stringMap.find("") != stringMap.end()) {
                addToAns(ans, i, stringMap[""]);
                addToAns(ans, stringMap[""], i);
            }
            if (stringMap.find(convert(words[i])) != stringMap.end() && i != stringMap[convert(words[i])])
                addToAns(ans, i, stringMap[convert(words[i])]);
            for(int len = 1; len < words[i].size(); len++) {
                if (isPalindrome(words[i].substr(0, len)) && stringMap.find(convert(words[i].substr(len))) != stringMap.end())
                    addToAns(ans, stringMap[convert(words[i].substr(len))], i);
                int end = words[i].size()-len;
                if (isPalindrome(words[i].substr(end)) && stringMap.find(convert(words[i].substr(0, end))) != stringMap.end())
                    addToAns(ans, i, stringMap[convert(words[i].substr(0, end))]);
            }
        }
        return ans;
    }
    string convert(string s) {
        string ss = s;
        int left = 0, right = ss.size()-1;
        while (left < right) {
            swap(ss[left], ss[right]);
            left++;
            right--;
        }
        return ss;
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void addToAns(vector<vector<int> >& ans, int x, int y) {
        vector<int> record;
        record.push_back(x);
        record.push_back(y);
        ans.push_back(record);
    }
};
}

int main() {
  vector<string> words;
  words.push_back("a");
  words.push_back("");
  vector<vector<int> > ans = (new palindrome_pairs::Solution())->palindromePairs(words);
  for (auto pair : ans) {
    cout << "(";
    cout << pair[0];
    cout << ",";
    cout << pair[1];
    cout << ") ";
  }
}

