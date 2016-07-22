/**
 * Compare Version numbers
 * Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
 *
 *solution: 从头开始，分析每两个"."之间的字符串大小，先把字符串截断前缀'0'，如果截断后谁的长度大谁大，如果长度相等，则比较
 *字符串大小。
 * time complexity: O(n)
 * space complexity: O(1)
 */

#include <iostream>
using namespace std;

namespace compare_version_numbers {
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int start1 = 0, start2 = 0;
        while (start1 < version1.size() && start2 < version2.size()) {
            int end1 = start1;
            int end2 = start2;
            while (end1 < version1.size() && version1[end1] != '.')
                end1++;
            while (end2 < version2.size() && version2[end2] != '.')
                end2++;
            while (start1 < end1 && version1[start1] == '0')
                start1++;
            while (start2 < end2 && version2[start2] == '0')
                start2++;
            if (end1 - start1 > end2 - start2)
                return 1;
            else if (end1 - start1 < end2 - start2)
                return -1;
            else {
                while (start1 < end1 && start2 < end2) {
                    if (version1[start1] < version2[start2])
                        return -1;
                    else if (version1[start1] > version2[start2])
                        return 1;
                    start1++;
                    start2++;
                }
            }
            start1 = end1 + 1;
            start2 = end2 + 1;
        }
        while (start1 < version1.size()) {
            if (version1[start1] > '0' && version1[start1] <= '9')
                return 1;
            start1++;
        }
        while (start2 < version2.size()) {
            if (version2[start2] > '0' && version2[start2] <= '9')
                return -1;
            start2++;
        }
        return 0;
    }
};
}
