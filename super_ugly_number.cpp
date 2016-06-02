/**
 * Super ugly number
 * Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

solution:

time complexity: O(n*d), 其中d是素数个数
space complexity: O(d)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace super_ugly_number {
class Solution {
public:
    struct node
    {
        int val, index;
        node(int val_, int index_): val(val_), index(index_){}
    };
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<node> factors(primes.size(), node(0, 0));
        for (int i=0; i<primes.size(); i++)
            factors[i].val = primes[i];
        vector<int> records(n, 0);
        records[0] = 1;
        for (int i = 1; i < n; i++) {
            int small = INT_MAX;
            for (int j = 0; j < factors.size(); j++) {
                if (factors[j].val*records[factors[j].index] < small) {
                    small = factors[j].val*records[factors[j].index];
                }
            }
            records[i] = small;
            for (int j = 0; j < factors.size(); j++) {
                while (factors[j].val * records[factors[j].index] <= records[i])
                    factors[j].index++;
            }
        }
        return records[n-1];
    }
};
}
int main_super_ugly_number() {
  int data[] = {2, 7, 13, 19};
  vector<int> primes(data, data+4);
  cout << (new super_ugly_number::Solution())->nthSuperUglyNumber(4, primes);
}
