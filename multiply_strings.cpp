/**
 * Multiply strings
 * Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
Subscribe to see which companies asked this question

solution : convert the string num1 and num2 to be vector<int> digit1 and digit2.
res[i+j+2] += digit1[i] + digit2[j];
After all, res[i-1] += res[i]/10; res[i] %= 10;
 */

#include <iostream>
#include <vector>
using namespace std;

namespace multiply_strings {
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) {
            return "0";
        }
        vector<int> digit1 (num1.size(), 0);
        vector<int> digit2 (num2.size(), 0);
        vector<int> res(num1.size() + num2.size() + 1, 0);
        for (int i = 0; i < num1.size(); i++) {
            digit1[i] = num1[i] - '0';
        }
        for (int j = 0; j < num2.size(); j++) {
            digit2[j] = num2[j] - '0';
        }
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                res[i+j+2] += digit1[i] * digit2[j];
            }
        }
        for (int i = num1.size() + num2.size(); i > 0; i--) {
            res[i-1] += res[i]/10;
            res[i] %= 10;
        }
        int index = 0;
        while (index <= num1.size() + num2.size() && res[index] == 0) {
            index++;
        }
        if (index > num1.size() + num2.size()) {
            return "0";
        }
        string ans;
        while (index <= num1.size() + num2.size()) {
            char ch = res[index] + '0';
            ans += ch;
            index++;
        }
        return ans;
    }
};
}
