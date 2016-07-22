/**
 * Valid perfect square
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
 */

#include <iostream>
using namespace std;

namespace valid_perfect_square {
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1)
            return true;
        long long left = 1, right = num/2;
        while (left <= right) {
            long long mid = (left + right)/2;
            cout << mid << endl;
            if (mid * mid == num)
                return true;
            else if (mid * mid < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
}

int main_valid_perfect_square() {
  cout << "ha" << endl;
  //(new valid_perfect_square::Solution())->isPerfectSquare(808201);
}
