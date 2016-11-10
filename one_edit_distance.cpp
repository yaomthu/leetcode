/**
 * One edit distance
 * Given two strings S and T, determine if they are both one edit distance apart.
 */

#include <iostream>
using namespace std;

namespace one_edit_distance {
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() > t.size())
            return isOneEditDistance(t, s);
        if (t.size() - s.size() > 1)
            return false;
        if (s.size() == t.size()) {
            int count = 0;
            for (int i = 0, j = 0; i < s.size() && j < t.size(); i++, j++)
                if (s[i] != t[i]) {
                    count++;
                    if (count > 1)
                        return false;
                }
            return count == 1;
        } else {
            int i = 0, j = 0;
            int count = 0;
            while (i < s.size() && j < t.size()) {
                if (s[i] != t[j]) {
                    count++;
                    if (count > 1)
                        return false;
                    j++;
                } else {
                    i++;
                    j++;
                }
            }
            return true;
        }
    }
};
}
