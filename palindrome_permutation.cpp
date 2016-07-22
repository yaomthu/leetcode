/**
 *  Palindrome Permutation
 *  Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Show Hint
Show Company Tags
Show Tags
Show Similar Problems
 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace palindrome_permutation {
class Solution {
public:
    bool canPermutePalindrome(string s) {
        if (s.empty())
            return true;
        vector<int> cmap(256, 0);
        int total = 0;
        for (int i = 0; i < s.size(); i++) {
            cmap[s[i]]++;
            if ((cmap[s[i]] & 1) == 1)
                total++;
            else
                total--;
        }
        if (total > 1)
            return false;
        return true;
    }
};
}
