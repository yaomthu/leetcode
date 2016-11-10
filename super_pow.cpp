/**
 * Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024

solution: link: https://discuss.leetcode.com/topic/50489/c-clean-and-short-solution
 */

#include <iostream>
#include <vector>
using namespace std;

namespace super_pow {
class Solution {
public:
    const int base = 1337;
    int superPow(int a, vector<int>& b) {
        if (b.empty()) {
            return 1;
        }
        int last = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last) % base;
    }

    int powmod(int a, int k) {
        a %= base;
        int result = 1;
        for (int i = 0; i < k; i++) {
            result = (result * a) % base;
        }
        return result;
    }
};
}
