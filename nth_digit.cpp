/**
 * Nth Digit
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 */

#include <iostream>
using namespace std;
namespace nth_digit {
class Solution {
public:
    int findNthDigit(int n) {
        long long left = 1, right = 9;
        int digits = 1;
        int ans;
        while (true) {
            long long count = (right - left + 1) * digits;
            if (n <= count) {
                int index = (n - 1) / digits;
                string num = to_string(left + index);
                int restDigits = n - index * digits;
                int i = 1;
                while (i < restDigits) {
                    i++;
                }
                ans = num[i-1] - '0';
                break;
            } else {
                n -= count;
                digits++;
                left *= 10;
                right = right*10 + 9;
            }
        }
        return ans;
    }
};
}

int main_nth_digit() {
  cout << (new nth_digit::Solution())->findNthDigit(1000000000);
}
