/**
 * Count numbers with unique digits
 * Given an integer n, count all numbers with unique digits, x, where 0 ≤ x ≤ 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x ≤ 100, excluding [11,22,33,44,55,66,77,88,99,100])
solution: 抓住规律，分别分析个位的情况，十位的情况，百位的情况。。。。记录考虑 n = 0 的情况
time complexity: O(n)
space complexity: O(1)
 */

#include <iostream>
using namespace std;

namespace count_numbers_with_unique_digits {
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0;
        if (n == 0)
            return 2;
        for (int i=1; i<=n; i++) {
            if (i == 1)
                ans += 10;
            else {
                int temp = 9;
                for (int j=2, choice = 9; j<=i && choice >= 0; j++, choice--)
                    temp *= choice;
                ans += temp;
            }
        }
        return ans;
    }
};
}
