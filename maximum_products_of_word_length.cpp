/**
 * Maximum Product of Word Lengths
 * Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

solution: 每个word用一个int来记录都有哪些字符出现。
time complexity: O(n^2)
space complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace maximum_products_of_word_length {
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size() < 2)
            return 0;
        vector<int> record(words.size(), 0);
        for (int i=0; i<words.size(); i++) {
            for (int j=0; j<words[i].size(); j++)
                record[i] |= (1<<(words[i][j]-'a'));
        }
        int ans = 0;
        for (int i=0; i<words.size()-1; i++) {
            for (int j=i+1; j<words.size(); j++) {
                if ((record[i] & record[j]) == 0 && words[i].size()*words[j].size() > ans)
                    ans = words[i].size()*words[j].size();
            }
        }
        return ans;
    }
};
}

int main_maximum_products_of_word_length() {
  string datas[] = {"abcw","baz","foo","bar","xtfn","abcdef"};
  vector<string> words(datas, datas+6);
  cout << (new maximum_products_of_word_length::Solution())->maxProduct(words);
}
