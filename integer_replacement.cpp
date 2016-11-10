/**
 * Integer replacement
 * Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1

solution: when the last digit is 0, use /2 operation. When last two digits are 11, use +1 operation, otherwise, use -1 operation.
Corner case is n=3.
 */
#include <iostream>
using namespace std;

namespace integer_replacement {
class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        long long m = n;
        while (m > 3) {
            if ((m & 1) == 0) {
                m >>= 1;
            } else if ((m & 2) == 2) {
                m++;
            } else {
                m--;
            }
            ans++;
        }
        return ans + m - 1;
    }
};
}

int main_integer_replacement() {
  (new integer_replacement::Solution())->integerReplacement(2147483647);
}
