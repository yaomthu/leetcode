/*
 * Ugly number ii
 * Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

 * solution: 维护三个下标 index2, index3, index5 分别记录考虑最大的乘2，乘3，乘5的数。
 * time complexity: O(n)
 * space complexity O(1)
 * */

#include <iostream>
#include <vector>
using namespace std;

namespace ugly_number_ii {
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNums(n, 0);
        uglyNums[0] = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        for (int i=1; i<n; i++) {
            int minimum = getMin(uglyNums[index2]*2, uglyNums[index3]*3, uglyNums[index5]*5);
            uglyNums[i] = minimum;
            while (uglyNums[index2]*2 <= minimum)
                index2++;
            while (uglyNums[index3]*3 <= minimum)
                index3++;
            while (uglyNums[index5]*5 <= minimum)
                index5++;
        }
        return uglyNums.back();
    }
    int getMin(int a, int b, int c) {
        int ans = INT_MAX;
        if (a < ans)
            ans = a;
        if (b < ans)
            ans = b;
        if (c < ans)
            ans = c;
        return ans;
    }
};
}

