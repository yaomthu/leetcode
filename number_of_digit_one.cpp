/**
 * Number of digit one
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

solution: 假设一个数字的十进制表示为abcde，当计算百位为‘1’出现多少次时：
(1) 如果c==0, 则百位出现1的次数为(ab)*100;
(2) 如果c==1，则百位出现1的次数为(ab)*100 + (de)+1
(3) 如果c > 1，则百位出现1的次数为(ab+1)*100。

time complexity: O(n)
space complexity: O(1)
 */

#include <iostream>
using namespace std;

namespace number_of_digit_one {
class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;
        long long power = 1;
        while (n/power > 0) {
            power *= 10;
        }
        power /= 10;
        int ans = 0;
        while (power > 0) {
            int up = n/power/10;
            int cur = n/power%10;
            int down = n%power;
            if (cur == 0)
                ans += up*power;
            else if (cur == 1)
                ans += up*power + down+1;
            else
                ans += (up+1)*power;
            power /= 10;
        }
        return ans;
    }
};
}
