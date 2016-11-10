/**
 * Strobogrammatic number
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.

solution: consider about the character '0', '1', '6, '8', '9'.
 */

#include <iostream>
using namespace std;

namespace strobogrammatic_number {
class Solution {
public:
    bool isStrobogrammatic(string num) {
        if (num.empty() || (num.size() > 1 && num[0] == '0'))
            return false;
        string res;
        for (int i = num.size()-1; i >= 0; i--) {
            if (!valid(num[i]))
                return false;
            res += mapping(num[i]);
        }
        return res == num;
    }
    bool valid(char a) {
        return a == '0' || a == '1' || a == '6' || a == '8' || a == '9';
    }
    char mapping(char a) {
        if (a == '0' || a == '1' || a == '8')
            return a;
        if (a == '6')
            return '9';
        else
            return '6';
    }
};
}
