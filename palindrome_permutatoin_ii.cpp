/**
 * Palindrome permutation ii
 * Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

namespace palindrome_permutation_ii {
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> ans;
        if (s.empty())
            return ans;
        vector<int> cmap(256, 0);
        for (int i = 0; i < s.size(); i++)
            cmap[s[i]]++;
        int odd = 0, oddIndex = -1;
        for (int i = 0; i < 256; i++) {
            if (cmap[i] % 2 == 1) {
                odd++;
                oddIndex = i;
            }
        }
        if (odd > 1)
            return ans;
        else {
            string mid;
            if (odd == 1)
                mid += (char)oddIndex;
            string left;
            for (int i = 0 ; i < 256; i++) {
                if (cmap[i] > 0)
                    left += string(cmap[i]/2, (char)i);
            }
            permutation(left, mid, 0, ans);
            return ans;
        }
    }
    void permutation(string& left, string mid, int start, vector<string>& ans) {
        if (start == left.size()) {
            string right = left;
            reverse(right.begin(), right.end());
            ans.push_back(left + mid + right);
            return;
        }
        unordered_set<char> record;
        for (int i = start; i < left.size(); i++) {
            if (record.find(left[i]) == record.end()) {
                int temp = left[start];
                left[start] = left[i];
                left[i] = temp;
                permutation(left, mid, start+1, ans);
                temp = left[start];
                left[start] = left[i];
                left[i] = temp;
                record.insert(left[i]);
            }
        }
    }
};
}
