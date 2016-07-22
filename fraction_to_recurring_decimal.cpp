/**
 * Fraction to Recurring Decimal My Submissions QuestionEditorial Solution
Total Accepted: 31798 Total Submissions: 206775 Difficulty: Medium
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
 */

#include <iostream>
#include <unordered_map>
using namespace std;

namespace fraction_to_recurring_decimal {
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string ans;
        if ((numerator>0) ^ (denominator>0))
            ans += '-';
        long long numer = numerator;
        long long denom = denominator;
        numer = abs(numer);
        denom = abs(denom);
        ans += to_string(numer/denom);
        if (numer % denom == 0)
            return ans;
        numer %= denom;
        ans += ".";
        unordered_map<int, int> record;
        while (numer > 0) {
            if (record.find(numer) == record.end()) {
                record[numer] = ans.size();
                numer *= 10;
                char ch = numer/denom + '0';
                ans += ch;
                numer %= denom;
            } else {
                int start = record[numer];
                ans += '0';
                for (int i=ans.size()-1; i>start; i--)
                    ans[i] = ans[i-1];
                ans[start] = '(';
                ans += ')';
                break;
            }
        }
        return ans;
    }
};
}
