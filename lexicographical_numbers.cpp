/**
 * Lexicographical numbers
 * Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.

Subscribe to see which companies asked this question

 *
 */
#include <iostream>
#include <vector>
using namespace std;
namespace lexicographical_order {
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int start = 1; start <= 9; start++) {
            dfs(ans, start, n);
        }
        return ans;
    }

    void dfs(vector<int>& ans, int sum, int n) {
        if (sum <= n) {
            ans.push_back(sum);
        } else {
            return;
        }
        for (int next = 0; next <= 9; next++) {
            if (sum*10+next > n) {
                break;
            }
            dfs(ans, sum*10+next, n);
        }
    }
};

class SolutionIterative {
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int num = 1;
        for (int i = 0; i < n; i++) {
            ans.push_back(num);
            if (num * 10 <= n) {
                num *= 10;
            } else {
                num++;
                if (num > n) {
                    num = n / 10 + 1;
                }
                while (num % 10 == 0) {
                    num /= 10;
                }
            }
        }
        return ans;
    }
};
};
}

