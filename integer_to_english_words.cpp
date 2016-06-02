/**
 * Integer to English words
 * Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

solution: 注意 0 的情况。
 */

#include <iostream>
using namespace std;

namespace integer_to_english_words {
class Solution {
public:
    string numberToWords(int num) {
        int power = 1000000000;
        string ans;
        if (num >= power) {
            ans += helper(num/power);
            ans += " Billion";
        }
        num %= power;
        power = power/1000;
        if (num >= power) {
            if (ans.size())
                ans += " ";
            ans += helper(num/power);
            ans += " Million";
        }
        num %= power;
        power = power/1000;
        if (num >= power) {
            if (ans.size())
                ans += " ";
            ans += helper(num/power);
            ans += " Thousand";
        }
        num %= power;
        power /= 1000;
        if (num > 0) {
            if (ans.size())
                ans += " ";
            ans += helper(num);
        } else {
            if (ans.empty())
                ans = "Zero";
        }
        return ans;
    }
    string helper(int num) {
        string ans;
        if (num >= 100) {
            ans += getWord(num/100) + " Hundred";
            num %= 100;
        }
        if (num >= 10) {
            if (ans.size())
                ans += " ";
            if (num <= 20) {
                ans += getWord(num);
                return ans;
            } else {
                ans += getWord(num/10*10);
                num %= 10;
            }
        }
        if (num > 0) {
            if (ans.size())
                ans += " ";
            ans += getWord(num);
        }
        return ans;
    }

    string getWord(int num)
    {
        switch(num)
        {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
            case 20: return "Twenty";
            case 30: return "Thirty";
            case 40: return "Forty";
            case 50: return "Fifty";
            case 60: return "Sixty";
            case 70: return "Seventy";
            case 80: return "Eighty";
            case 90: return "Ninety";
            default:
                break;
        }
        return "";
    }
};
}

int main_integer_to_english_words() {
  cout << (new integer_to_english_words::Solution())->numberToWords(INT_MAX);
}
