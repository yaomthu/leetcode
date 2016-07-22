/**
 * Rearrange string k distance apart
 * Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
str = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
Example 2:
str = "aaabc", k = 3

Answer: ""

It is not possible to rearrange the string.
Example 3:
str = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.

solution: 贪心算法。使用priority_queue<pair<int,char>>以记录候选字母（按字母次数从大到小排序）。
每轮选出次数最大的k个字母（最后一轮可能没有k个元素），前一轮使用过的字母cache起来，如果这些字母的个数仍然大于0，
则放入到下一轮的候选字母里。

time complexity：O(nlogn)
space complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

namespace rearrange_string_k_distance_apart {
class Solution {
public:
    string rearrangeString(string str, int k) {
        if(k == 0) return str;
        int length = (int)str.size();

        string res;
        unordered_map<char, int> dict;
        for (int i = 0; i < str.size(); i++)
            dict[str[i]]++;
        priority_queue<pair<int, char> > pq;
        for (auto element : dict) {
            pq.push(make_pair(element.second, element.first));
        }
        while (pq.size()) {
            int count = k < length? k : length;
            vector<pair<int,char> > cache;
            for (int i = 0; i < count; i++) {
                if (pq.empty())
                    return "";
                auto top = pq.top();
                pq.pop();
                res.push_back(top.second);
                if (--top.first > 0)
                    cache.push_back(top);
            }
            length -= count;
            for (auto element : cache)
                pq.push(element);
        }
        return res;
    }
};
}

int main_rearrange_string_k_distance_apart() {
  string str = "aaadbbcc";
  cout << (new rearrange_string_k_distance_apart::Solution())->rearrangeString(str, 2);
}

